valorDoProduto = float(input('Valor do produto: R$'))
valorPago = float(input('Valor pago: R$'))
troco = valorPago - valorDoProduto

if troco > 0:
    print('O seu troco é R$ {:.2f}'.format(troco))
else:
    print('Você precisa pagar mais R$ {:.2f}'.format(-1*troco))
