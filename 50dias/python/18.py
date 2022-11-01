import random

numeroGerado = random.randint(0,49)

print('Eu pensei em um numero entre 0 e 49!')
print('Tente adivinhar o numero que eu pensei!')

naoAdivinhouNumero = True
while naoAdivinhouNumero:
    numeroDigitado = int(input('Digite um numero: '))
    if numeroDigitado == numeroGerado:
        print('PARABÉNS, VOCÊ ACERTOU.')
        print('O NÚMERO QUE EU TINHA PENSADO ERA O ' + str(numeroGerado))
        naoAdivinhouNumero = False
    elif numeroDigitado < numeroGerado:
        print('O seu número é menor, tente um numero ' \
              'maior que ' + str(numeroDigitado))
    else:
        print('O seu número é maior, tente um numero ' \
              'menor que ' + str(numeroDigitado))
