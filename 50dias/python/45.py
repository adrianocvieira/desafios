import random

def EmbaralhaPalavraMantendoPrimeiraUltima(palavra):
    tamanhoPalavra = len(palavra)
    novaPalavra = palavra
    if tamanhoPalavra > 1:
        meio = palavra[1:tamanhoPalavra-1]
        novoMeio = ''.join(random.sample(meio, len(meio)))
        novaPalavra = palavra[0] + novoMeio + palavra[tamanhoPalavra-1]
    return novaPalavra

palavra = input('Digite uma palavra: ')
palavra = EmbaralhaPalavraMantendoPrimeiraUltima(palavra)
print(palavra)