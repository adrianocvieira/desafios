primeiro = int(input('Digite o primeiro valor: '))
segundo = int(input('Digite o segundo valor: '))
terceiro = int(input('Digite o terceiro valor: '))

maiorValor = primeiro
if segundo > primeiro and segundo > terceiro:
    maiorValor = segundo
elif terceiro > primeiro and terceiro > segundo:
    maiorValor = terceiro
print('O maior valor digitado é ' + str(maiorValor))

menorValor = primeiro
if segundo < primeiro and segundo < terceiro:
    menorValor = segundo
elif terceiro < primeiro and terceiro < segundo:
    menorValor = terceiro
print('O menor valor digitado é ' + str(menorValor))
