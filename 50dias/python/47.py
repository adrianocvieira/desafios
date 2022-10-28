import os

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

def ImprimePedido(pedidoAtual):
    precoTotal = 0.00
    print('==========================================')
    print('               Seu pedido                 ')
    print('==========================================')
    print('  Produto             |  Quant   |  Preco ')
    print('------------------------------------------')
    for codigo in codigos:
        quantidade = pedidoAtual[codigo]
        if quantidade > 0:
            produto = produtos[codigo]
            nome = produto['nome'].ljust(prodStringSize)
            preco = produto['preco']
            msg = '  {nome}|  {quant}     |  R$ {preco:.2f}'.format(nome=nome,
                                                                    quant=quantidade,
                                                                    preco=quantidade * preco)
            print(msg)
            precoTotal += quantidade * preco

    print('------------------------------------------')
    print('  Preco Total: R$ {preco:.2f}'.format(preco=precoTotal))
    print('------------------------------------------')

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

    pedidosTotais[codigoPedido] = {'nome': nomeUsuario,
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

def ImprimePedidosDoDia():
    print(pedidosTotais)
    for codigoPedido, pedidoUsuario in pedidosTotais.items():
        print(' Pedido n: {}'.format(codigoPedido))
        print(' Cliente: {}'.format(pedidoUsuario['nome']))
        ImprimePedido(pedidoUsuario['pedido'])

def main():
    opcaoSistema = -1
    while opcaoSistema != 9:
        opcaoSistema = ImprimeMenuSistema()
        if opcaoSistema != 9:
            LePedidoDoUsuario()

    ImprimePedidosDoDia()

main()
