def EhPontuacao(caractere):
    return caractere in ['.', '!', '?', ';', ':', ',']

def EhNumero(caractere):
    return caractere in ['1', '2', '3', '4', '5',
                         '6', '7', '8', '9', '10']

def EhVogal(caractere):
    return caractere in ['a', 'e', 'i', 'o', 'u']

def Contabiliza(texto, filtro):
    quantidade = 0
    for caractere in texto.lower():
        if filtro(caractere):
            quantidade += 1
    return quantidade

textoEntrada = input('Digite uma string: ')

tamanhoTexto = len(textoEntrada)
quantPontuacoes = Contabiliza(textoEntrada, EhPontuacao)
quantNumeros = Contabiliza(textoEntrada, EhNumero)
quantVogais = Contabiliza(textoEntrada, EhVogal)

print('a) Tamanho da string: ' + str(tamanhoTexto))
print('b) Caracteres de pontuacao: ' + str(quantPontuacoes))
print('c) Quantos numeros: ' + str(quantNumeros))
print('d) Quantas vogais: ' + str(quantVogais))
