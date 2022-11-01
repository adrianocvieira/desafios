valorDoAluguel = float(input('Digite o valor do aluguel: '))
diasDeAtraso = float(input('Digite os dias de atraso: '))

multa = valorDoAluguel * 0.03
jurosSimples = valorDoAluguel * 0.005 * diasDeAtraso
valorTotal = valorDoAluguel + multa + jurosSimples

print('O valor a ser pago é {:.2f}'.format(valorTotal))
