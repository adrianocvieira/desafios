
def LerTextoUsuario(mensagem):
    texto = input(mensagem)
    return texto

def CodificaTexto(textoOriginal):
    textoCodificado = ""
    for letra in textoOriginal:
        textoCodificado += chr(ord(letra) + 3)
    return textoCodificado

def main():
    textoOriginal = LerTextoUsuario("Digite um texto:")
    textoCodificado = CodificaTexto(textoOriginal)

    print('Texto codificado: ' + textoCodificado)

main()