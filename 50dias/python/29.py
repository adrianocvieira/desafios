def LerTextoUsuario():
    texto = input('Digite um texto: ')
    return texto

def EhVogal(letra):
    return letra in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

def CensuraTexto(texto):
    textoCensurado = ""
    vogais = ""
    for i in range(len(texto)):
        if EhVogal(texto[i]):
            textoCensurado += '*'
            vogais += texto[i]
        else:
            textoCensurado += texto[i]
    return textoCensurado, vogais

def main():
    texto = LerTextoUsuario()

    textoCensurado, vogais = CensuraTexto(texto)
    print('Texto censurado: ' + textoCensurado)
    print('Vogais: ' + vogais)


main()