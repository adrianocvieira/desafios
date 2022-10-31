VALOR_METRO_QUADRADO = 7592.00

frente_terreno = float(input('Digite a frente do terreno (m): '))
fundos_terreno = float(input('Digite os fundos do terreno (m): '))

area = frente_terreno * fundos_terreno
preco_do_terreno = area * VALOR_METRO_QUADRADO

print('O valor da áre a do terreno é {:.2f}m²'.format(area))
print('O valor do terreno é R$ {:.2f}'.format(preco_do_terreno))
