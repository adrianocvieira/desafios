import math

numero1 = float(input('Digite o primeiro numero: '))
numero2 = float(input('Digite o segundo numero: '))

soma = numero1 + numero2
quadrado_primeiro = numero1**2
quadrado_segundo = numero2**2
primeiro_vs_quadrado_segundo = numero1 * quadrado_segundo
soma_dos_quadrados = quadrado_primeiro + quadrado_segundo
seno_subtracao_valores = math.sin(numero1 - numero2)

print('Vamos para os resultados!')
print('a) {}'.format(soma))
print('b) {}'.format(primeiro_vs_quadrado_segundo))
print('c) {}'.format(quadrado_primeiro))
print('d) {}'.format(soma_dos_quadrados))
print('e) {}'.format(seno_subtracao_valores))
