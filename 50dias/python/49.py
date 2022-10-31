import os
import json
from datetime import datetime

prodStringSize = 20
produtos = {}
pedidosTotais = {}
codigoPedido = 0

def LeArquivoJson(nomeDoArquivo):
    conteudo = {}
    with open(nomeDoArquivo) as arquivoJson:
        conteudo = json.load(arquivoJson)
    return conteudo
    
def EscreveArquivoJson(nomeDoArquivo, conteudo):
    with open(nomeDoArquivo, 'w') as arquivoJson:
        json.dump(conteudo, arquivoJson, indent=4)

def EscreveTextoNoArquivo(texto, nomeDoArquivo):
    output_file = open(nomeDoArquivo, 'a')
    output_file.write(texto)
    output_file.close()

def ProdutoExiste(codigoProduto):
    return codigoProduto in produtos.keys()

def ImprimeCardapio():
    print('------------------------------------------')
    print('  Produto             |  Codigo  |  Preco ')
    print('------------------------------------------')
    for codigo in produtos.keys():
        produto = produtos[codigo]
        nome = produto['nome'].ljust(prodStringSize)
        preco = produto['preco']
        msg = '  {nome}|  {cod}     |  R$ {preco:.2f}'.format(nome=nome,
                                                              cod=codigo,
                                                              preco=preco)
        print(msg)
    print('------------------------------------------')


def GeraTextoPedido(pedidoAtual):
    precoTotal = 0.00
    textoPedido = '==========================================\n'
    textoPedido += '                 Pedido                 \n'
    textoPedido += '==========================================\n'
    textoPedido += '  Produto             |  Quant   |  Preco \n'
    textoPedido += '------------------------------------------\n'
    for codigo in produtos.keys():
        if codigo in pedidoAtual.keys():
            quantidade = pedidoAtual[codigo]
            if quantidade > 0:
                produto = produtos[codigo]
                nome = produto['nome'].ljust(prodStringSize)
                preco = produto['preco']
                msg = '  {nome}|  {quant}     |  R$ {preco:.2f}\n'.format(nome=nome,
                                                                        quant=quantidade,
                                                                        preco=quantidade * preco)
                textoPedido += msg
                precoTotal += quantidade * preco

    textoPedido += '------------------------------------------\n'
    textoPedido += '  Preco Total: R$ {preco:.2f}\n'.format(preco=precoTotal)
    textoPedido += '------------------------------------------\n'
    return textoPedido

def ImprimePedido(pedidoAtual):
    textoPedido = GeraTextoPedido(pedidoAtual)
    print(textoPedido)

def ImprimeMenuPedidos(pedidoAtual):
    ImprimeCardapio()
    ImprimePedido(pedidoAtual)

def RegistraPedido(pedidoAtual, codigo, quantidade):
    pedidoAtual[codigo] += quantidade


def LeOpcoesDoUsuario():
    opcao = input('Digite o codigo do produto (0 para sair): ')
    quantidade = -1
    if opcao != "0":
        quantidade = int(input('Digite a quantidade: '))
    return opcao, quantidade


def ValidaInformacoes(opcao, quantidade):
    produtoExiste = ProdutoExiste(opcao)
    quantidadeValida = quantidade > 0
    if not produtoExiste:
        print('\n  Codigo de produto nao encontrado!\n')
    elif not quantidadeValida:
        print('\n  Quantidade digitada eh invalida!\n')

    return produtoExiste and quantidadeValida


def CriaPedido():
    pedido = dict.fromkeys(produtos.keys(), 0)
    return pedido


def LePedidoDoUsuario():
    global codigoPedido
    codigoPedido += 1
    nomeUsuario = input('Digite o seu nome: ')
    pedidoAtual = CriaPedido()
    print(pedidoAtual)
    opcao = "-1"
    os.system('cls')
    while opcao != "0":
        ImprimeMenuPedidos(pedidoAtual)
        opcao, quantidade = LeOpcoesDoUsuario()
        if opcao != "0":
            os.system('cls')
            if ValidaInformacoes(opcao, quantidade):
                RegistraPedido(pedidoAtual, opcao, quantidade)

    agora = datetime.now()
    data = agora.strftime("%d/%m/%Y %H:%M:%S")
    pedidosTotais[codigoPedido] = {'nome': nomeUsuario,
                                   'data': data,
                                   'pedido': pedidoAtual}

    print('\n  O seu pedido é o número: {}'.format(codigoPedido))
    print('  Efetue o pagamento no caixa.')
    print('  Muito obrigado pelo seu pedido!')
    _ = input('\nTecle ENTER para sair!')

def OpcaoMenuPrincipalValida(opcao):
    return opcao == "1" or opcao == "8" or opcao == "9"

def ImprimeMenuSistema():
    print('==========================================')
    print('        Lancheria do Juquinha             ')
    print('==========================================')
    print('  1 - Fazer pedido')
    print('  8 - Cadastrar produto')
    print('  9 - Sair')
    print('------------------------------------------')
    opcao = "-1"
    while not OpcaoMenuPrincipalValida(opcao):
        opcao = input('Digite a opcao: ')
    return opcao

def GeraTextoPedidosDoDia():
    textoPedidosDia = ""
    for codigoPedido, pedidoUsuario in pedidosTotais.items():
        textoPedidosDia += ' Pedido n: {}\n'.format(codigoPedido)
        textoPedidosDia += ' Cliente: {}\n'.format(pedidoUsuario['nome'])
        textoPedidosDia += ' Data: {}\n'.format(pedidoUsuario['data'])
        textoPedidosDia += GeraTextoPedido(pedidoUsuario['pedido'])
    return textoPedidosDia

def GeraCabecalhoRelatorio(tituloCabecalho):
    agora = datetime.now()
    data = agora.strftime("%d/%m/%Y %H:%M:%S")

    textoCabecalho = "==============================================\n"
    textoCabecalho += "          " + tituloCabecalho + "\n"
    textoCabecalho += "               " + data + "\n"
    textoCabecalho += "==============================================\n"
    return textoCabecalho

def ImprimePedidosDoDia():
    textoRelatorioPedidosDoDia = GeraCabecalhoRelatorio("RELATORIO DE PEDIDOS DO DIA")
    textoRelatorioPedidosDoDia += GeraTextoPedidosDoDia()
    EscreveTextoNoArquivo(textoRelatorioPedidosDoDia, 'pedidos.txt')

def ImprimeRelatorioVendasDia():
    todosPedidosDoDia = CriaPedido()
    for codigoPedido, pedidoUsuario in pedidosTotais.items():
        for codigoProduto, quantidade in pedidoUsuario['pedido'].items():
            RegistraPedido(todosPedidosDoDia,
                           codigoProduto,
                           quantidade)

    textoRelatorioVendas = GeraCabecalhoRelatorio("RELATORIO VENDAS DO DIA")
    textoRelatorioVendas += GeraTextoPedido(todosPedidosDoDia)
    EscreveTextoNoArquivo(textoRelatorioVendas, 'relatorio.txt')

def ImprimeRelatoriosDoDia():
    ImprimePedidosDoDia()
    ImprimeRelatorioVendasDia()
    
def CadastraProduto():
    produtoExiste = True
    while produtoExiste:
        codigoNovoProduto = input('Digite o codigo do produto: ')
        produtoExiste = ProdutoExiste(codigoNovoProduto)
        if produtoExiste:
            print('Codigo do produto já existente!\n')
    nomeProduto = input('Digite o nome do produto: ')
    preco = float(input('Digite o preco do produto: '))
    produtos[codigoNovoProduto] = {"nome" : nomeProduto,
                                   "preco": preco}
    EscreveArquivoJson('produtos.json', produtos)

def PreencheSistema():
    global produtos
    produtos = LeArquivoJson('produtos.json')

def main():
    PreencheSistema()
    
    while True:
        os.system('cls')
        opcaoSistema = ImprimeMenuSistema()
        
        if opcaoSistema == "1":
            LePedidoDoUsuario()
        elif opcaoSistema == "8":
            CadastraProduto()
        else:
            break

    ImprimeRelatoriosDoDia()


main()
