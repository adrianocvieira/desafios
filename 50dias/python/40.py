QUANTIDADE_PROJETOS = 10
orcamentoProjetos = [0] * 10

def LeCodigoProjeto():
    codigoProjeto = -1
    codigoProjetoValido = False
    while (not codigoProjetoValido):
        msg = 'Digite o codigo do projeto[1-{lim}]: '.format(lim=QUANTIDADE_PROJETOS)
        codigoProjeto = int(input(msg))
        codigoProjetoValido = 0 <= codigoProjeto <= QUANTIDADE_PROJETOS
    return codigoProjeto

def LeValor():
    valor = -1.00
    valorValido = False
    while (not valorValido):
        valor = float(input('Digite o valor [>0]: '))
        valorValido = valor > 0.00
    return valor

def LeTipo():
    tipo = ' '
    tipoValido = False
    while (not tipoValido):
        tipo = input('Digite o tipo [R/D]: ')
        tipoValido = tipo == 'R' or tipo == 'D'
    return tipo

def LeInformacoesDoUsuario():
    codigoProjeto = LeCodigoProjeto()
    valor = 0.00
    tipo = ' '
    if codigoProjeto > 0:
        valor = LeValor()
        tipo = LeTipo()
    return codigoProjeto, valor, tipo


def RegistraInformacoes(codigoProjeto, valor, tipo):
    if tipo == 'R':
        orcamentoProjetos[codigoProjeto - 1] += valor
    else:
        orcamentoProjetos[codigoProjeto - 1] -= valor

def ImprimeInformacoesProjeto():
    for i in range(QUANTIDADE_PROJETOS):
        print('--------------------------------')
        print('Projeto codigo {cod}'.format(cod=i+1))
        print('  Saldo: R$ {val:.2f}'.format(val=orcamentoProjetos[i]))
        print('--------------------------------')


def main():
    codigoProjeto = -1
    while codigoProjeto != 0:
        codigoProjeto, valor, tipo = LeInformacoesDoUsuario()
        if codigoProjeto > 0:
            RegistraInformacoes(codigoProjeto, valor, tipo)

    ImprimeInformacoesProjeto()

main()