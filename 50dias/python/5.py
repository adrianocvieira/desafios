n = -1
while n <= 0:
    n = int(input("Digite um numero inteiro positivo: "))

soma = 0
for i in range(1, n+1):
    soma += i

print('O valor da soma de 1 até {n} é {soma}'.format(n=n,
                                                     soma=soma))
