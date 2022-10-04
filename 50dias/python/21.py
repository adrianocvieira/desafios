
def lerPalavrasDoArquivo(palavras):
    input_file = open('input.txt', 'r')
    conteudo = input_file.readlines()
    input_file.close()
    
    for linha in conteudo:
        palavrasDaLinha = linha.split()
        palavras += palavrasDaLinha
    
def ordenaPalavrasPorTamanhoEmOrdemDescrescente(palavras):
    palavras.sort(key = len, reverse=True)
    
def preencheMaioresPalavras(palavras, maioresPalavras):
    tamanhoMaiorPalavra =  len(palavras[0])
    for palavra in palavras:
        tamanhoPalavra = len(palavra)
        if tamanhoPalavra == tamanhoMaiorPalavra:
            maioresPalavras.append(palavra)
        else:
            break
        
def escreveNoArquivoDeSaida(maioresPalavras):
    mensagem = "\n\n"
    
    multiplasPalavras = len(maioresPalavras) > 1
    if multiplasPalavras:
        mensagem += "As maiores palavras são: "
    else :
        mensagem += "A maior palavra é: "
    
    output_file = open('output.txt', 'w')
    output_file.write(mensagem + '\n')
    
    for palavra in maioresPalavras:
        output_file.write(palavra)
        output_file.write('\n')
    output_file.close()
        
def main():
    palavras = []
    
    lerPalavrasDoArquivo(palavras)

    ordenaPalavrasPorTamanhoEmOrdemDescrescente(palavras)
    
    maioresPalavras = []
    preencheMaioresPalavras(palavras, maioresPalavras)
    
    escreveNoArquivoDeSaida(maioresPalavras)
    
main()