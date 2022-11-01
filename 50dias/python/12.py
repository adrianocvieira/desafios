def CalculaFatorial(numero):
    if numero == 0:
        return 1
    return numero * CalculaFatorial(numero-1)

def CalculaFatorialLoop(numero):
    fatorial = 1
    for n in range(1, numero+1):
        fatorial *= n
    return fatorial

def LeiaNumeroInteiroPositivo():
    numero = -1
    while numero < 0:
        numero = int(input('Digite um numero inteiro positivo: '))
    return numero

numero = LeiaNumeroInteiroPositivo()
fatorial = CalculaFatorial(numero)
fatorialComLaco = CalculaFatorialLoop(numero)

print('O fatorial de {n} é {fat}'.format(n=numero,
                                         fat=fatorial))
print('O fatorial com loop de {n} é {fat}'.format(n=numero,
                                                  fat=fatorialComLaco))
