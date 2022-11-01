def EhPrimo(n):
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

def LeNumeroInteiroPositivo():
    valor = -1
    while valor <= 0:
        valor = int(input('Digite um valor > 0: '))
    return valor

numero = LeNumeroInteiroPositivo()
mensagem = 'O numero ' + str(numero)
if EhPrimo(numero):
    mensagem += ' é PRIMO!'
else:
    mensagem += ' nao é PRIMO!'
print(mensagem)
