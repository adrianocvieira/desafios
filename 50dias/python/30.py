
def LerTextoUsuario(mensagem):
    texto = input(mensagem)
    return texto

def RemoveCensuraTexto(textoCensurado, vogais):
    contadorVogais = 0
    textoOriginal = ""
    for i in range(len(textoCensurado)):
        if textoCensurado[i] == '*':
            textoOriginal += vogais[contadorVogais]
            contadorVogais += 1
        else:
            textoOriginal += textoCensurado[i]
    return textoOriginal

def main():
    textoCensurado = LerTextoUsuario('Digite um texto: ')
    vogais = LerTextoUsuario('Digite as vogais censuradas: ')

    textoOriginal = RemoveCensuraTexto(textoCensurado, vogais)
    print('Texto original: ' + textoOriginal)

main()