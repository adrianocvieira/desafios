def LePalavrasDoArquivo():
    palavras = []
    input_file = open('input.txt', 'r')
    conteudo = input_file.readlines()
    input_file.close()

    for linha in conteudo:
        palavras.append(linha)
    return palavras

def RemoveColcheteEspacosDaString(entrada):
    entrada = entrada.replace(']', '')
    entrada = entrada.replace('[', '')
    entrada = entrada.replace(' ', '')
    return entrada

def ConverteListaStringsParaInteiros(entrada):
    entrada = RemoveColcheteEspacosDaString(entrada)

    inteirosEntrada = []
    if len(entrada) > 0:
        entrada = entrada.split(',')
        for palavra in entrada:
            inteirosEntrada.append(int(palavra))
    return inteirosEntrada

def ConverteArquivoParaListaInteiros():
    linhasDoArquivo = LePalavrasDoArquivo()

    listasDeInteiros = []
    for palavra in linhasDoArquivo:
        listaInteiros = ConverteListaStringsParaInteiros(palavra)
        listasDeInteiros.append(listaInteiros)
    return listasDeInteiros;

def OrdenaLista(lista):
    trocou = True
    while trocou:
        trocou = False
        for i in range(0, len(lista)-1):
            if lista[i] > lista[i+1]:
                aux = lista[i]
                lista[i] = lista[i+1]
                lista[i+1] = aux
                trocou = True

def OrdenaListas(listasLidas):
    for lista in listasLidas:
        OrdenaLista(lista)

'''
    Para encontrar o elemento faltante, você pode ordenar a 
    lista, visto que os elementos nao se repetem.
    exemplo:
        [4, 3, 1, 5, 9, 7, 8, 6, 10]
    ordenada:
        [1, 3, 4, 5, 6, 7, 8, 9, 10]
    O número 1 encontra-se na primeira posição
    mas o número 2 nao se encontra na segunda posição.
    Por este motivo o número DOIS está faltando.
    Se você encontrar todos elementos na posicao certa
    significa que o ultimo elemento é o faltante.
    Lembrando que os numeros (no exemplo) sao de 1 a 10
    e a lista tem 9 posicoes. Entao o numero DEZ
    está faltando.
'''

def EncontraElementoFaltante(lista):
    tamanhoLista = len(lista)
    print(lista)
    for i in range(0, tamanhoLista):
        if lista[i] != i + 1:
            return i+1
    return tamanhoLista+1

def EncontraElementoFaltanteNasListas(listasLidas):
    for lista in listasLidas:
        elemento = EncontraElementoFaltante(lista)
        print('O elemento faltando: {}'.format(elemento))

def main():
    listasLidas = ConverteArquivoParaListaInteiros()
    OrdenaListas(listasLidas)
    EncontraElementoFaltanteNasListas(listasLidas)

main()
