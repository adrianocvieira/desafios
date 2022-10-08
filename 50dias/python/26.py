def LePalavrasDoArquivo():
    palavras = []
    input_file = open('input.txt', 'r')
    conteudo = input_file.readlines()
    input_file.close()

    for linha in conteudo:
        palavras.append(linha)
    return palavras

def EscreveListaNoArquivo(lista):
    output_file = open('input.txt', 'a')
    output_file.write("\n----------------------\n")
    output_file.write(str(lista))
    output_file.write("\n----------------------\n")
    output_file.close()

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
        EscreveListaNoArquivo(lista)

def main():
    listasLidas = ConverteArquivoParaListaInteiros()
    OrdenaListas(listasLidas)

main()





















