import math

def LeiaEntradaUsuario():
    print('O formato da entrada deve ser o seguinte:')
    print('[1, 2, 3, 4, ..., 30]')
    entrada = input('Digite uma lista de inteiros: ')
    return entrada

def RemoveColcheteEspacosDaString(entrada):
    entrada = entrada.replace(']', '')
    entrada = entrada.replace('[', '')
    entrada = entrada.replace(' ', '')
    return entrada

def ConverteListaStringsParaInteiros(entrada):
    entrada = RemoveColcheteEspacosDaString(entrada)

    inteirosEntrada = []
    if (len(entrada) > 0):
        entrada = entrada.split(',')

        for palavra in entrada:
            inteirosEntrada.append(int(palavra))
    return inteirosEntrada

def EhQuadradoPerfeito(i):
    raizQuadradaTruncada = int(math.sqrt(i))
    return i == raizQuadradaTruncada**2

def EfetuaOperacoes(inteiros):
    if (len(inteiros) > 0):
        quadradosPerfeitos = []
        for i in inteiros:
            if (EhQuadradoPerfeito(i)):
                quadradosPerfeitos.append(i)

        print('Os valores da lista que são quadrados perfeito:')
        print(quadradosPerfeitos)
    else:
        print('Lista está vazia!')

def main():
    entrada = LeiaEntradaUsuario();
    inteirosEntrada = ConverteListaStringsParaInteiros(entrada)
    EfetuaOperacoes(inteirosEntrada)

main()







