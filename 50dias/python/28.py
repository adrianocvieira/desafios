import unicodedata

def RemovePontuacao(texto):
    textoEditado = texto.replace(' ', '')
    textoEditado = textoEditado.replace('.', '')
    textoEditado = textoEditado.replace(',', '')
    textoEditado = textoEditado.replace('!', '')
    textoEditado = textoEditado.replace('?', '')
    textoEditado = textoEditado.replace('-', '')
    textoEditado = textoEditado.replace(':', '')
    textoEditado = textoEditado.replace(';', '')
    return textoEditado

def RemoveAcentuacao(texto):
    normalized = unicodedata.normalize('NFD', texto)
    return normalized.encode('ascii', 'ignore').decode('utf8').casefold()

def NormalizaTexto(texto):
    textoEditado = RemovePontuacao(texto)
    textoEditado = RemoveAcentuacao(textoEditado)
    return textoEditado

def EhPalindromo(texto):
    texto = NormalizaTexto(texto)
    inicioTexto = 0
    fimTexto = len(texto) - 1

    while inicioTexto < fimTexto:
        if texto[inicioTexto] != texto[fimTexto]:
            return False
        inicioTexto += 1
        fimTexto -= 1
    return True

def main():
    texto = input('Digite um texto: ')
    ehPalindromo = EhPalindromo(texto)

    naoEh = "" if ehPalindromo else "não "
    mensagem = "O texto {}é palíndromo!".format(naoEh)
    print(mensagem)

main()