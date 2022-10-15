
def LerTextoUsuario(mensagem):
    texto = input(mensagem)
    return texto

def DecodificaTexto(textoCodificado):
    textoOriginal = ""
    for letra in textoCodificado:
        textoOriginal += chr(ord(letra) - 3)
    return textoOriginal

def main():
    textoCodificado = LerTextoUsuario("Digite um textoCodificado: ")
    textoDecodificado = DecodificaTexto(textoCodificado)

    print('Texto decodificado: ' + textoDecodificado)

main()