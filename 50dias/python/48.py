import os
from datetime import datetime

prodStringSize = 20
codigos = [100, 101, 102, 103, 104, 105]
produtos = {codigos[0]: {'nome': 'Cachorro Quente',
                         'preco': 1.20},
            codigos[1]: {'nome': 'Bauru Simples',
                         'preco': 1.30},
            codigos[2]: {'nome': 'Bauru com ovo',
                         'preco': 1.50},
            codigos[3]: {'nome': 'Hamburguer',
                         'preco': 1.20},
            codigos[4]: {'nome': 'Cheeseburguer',
                         'preco': 1.30},
            codigos[5]: {'nome': 'Refrigerante',
                         'preco': 1.00}}

pedidosTotais = {}
codigoPedido = 0


def EscreveTextoNoArquivo(texto, nomeDoArquivo):
    output_file = open(nomeDoArquivo, 'a')
    output_file.write(texto)
    output_file.close()

def ImprimeCardapio():
    print('------------------------------------------')
    print('  Produto             |  Codigo  |  Preco ')
    print('------------------------------------------')
    for codigo in codigos:
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
    textoPedido +='==========================================\n'
    textoPedido +='  Produto             |  Quant   |  Preco \n'
    textoPedido +='------------------------------------------\n'
    for codigo in codigos:
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
    opcao = int(input('Digite o codigo do produto (0 para sair): '))
    quantidade = -1
    if opcao != 0:
        quantidade = int(input('Digite a quantidade: '))
    return opcao, quantidade


def ValidaInformacoes(opcao, quantidade):
    produtoExiste = opcao in codigos
    quantidadeValida = quantidade > 0
    if not produtoExiste:
        print('\n  Codigo de produto nao encontrado!\n')
    elif not quantidadeValida:
        print('\n  Quantidade digitada eh invalida!\n')

    return produtoExiste and quantidadeValida


def CriaPedido():
    pedido = {codigos[0]: 0,
              codigos[1]: 0,
              codigos[2]: 0,
              codigos[3]: 0,
              codigos[4]: 0,
              codigos[5]: 0}
    return pedido


def LePedidoDoUsuario():
    global codigoPedido
    codigoPedido += 1
    nomeUsuario = input('Digite o seu nome: ')
    pedidoAtual = CriaPedido()
    opcao = -1
    os.system('cls')
    while opcao != 0:
        ImprimeMenuPedidos(pedidoAtual)
        opcao, quantidade = LeOpcoesDoUsuario()
        if opcao != 0:
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


def ImprimeMenuSistema():
    print('==========================================')
    print('        Lancheria do Juquinha             ')
    print('==========================================')
    print('  1 - Fazer pedido ')
    print('  9 - Sair ')
    print('------------------------------------------')
    opcao = -1
    while opcao != 1 and opcao != 9:
        opcao = int(input('Digite a opcao: '))
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

def main():
    opcaoSistema = -1
    while opcaoSistema != 9:
        os.system('cls')
        opcaoSistema = ImprimeMenuSistema()
        if opcaoSistema != 9:
            LePedidoDoUsuario()

    ImprimeRelatoriosDoDia()


main()
