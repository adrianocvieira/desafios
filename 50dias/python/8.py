celsius = float(input('Digite o valor da temperatura em Celsius: '))
fahrenheit = celsius * 1.8 + 32.00

mensagem = 'A temperatura de {celsius}C é equivalente a {fah}F'.format(celsius=celsius,
                                                                       fah=fahrenheit)
print(mensagem)