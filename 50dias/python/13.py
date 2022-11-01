def LeQuantidadeMoeda(nomeMoeda):
    quantidade = -1
    while quantidade < 0:
        quantidade = int(input(nomeMoeda + " : "))
    return quantidade

print('Hey Arthur, me diga quantas moedas de cada voce tem?')

quantUm = LeQuantidadeMoeda("1 centavo")
quantCinco = LeQuantidadeMoeda("5 centavos")
quantDez = LeQuantidadeMoeda("10 centavos")
quantVinteCinco = LeQuantidadeMoeda("25 centavos")
quantCinquenta = LeQuantidadeMoeda("50 centavos")
quantUmReal = LeQuantidadeMoeda("1 real")

valorTotal = quantUm * 0.01
valorTotal += quantCinco * 0.05
valorTotal += quantDez * 0.10
valorTotal += quantVinteCinco * 0.25
valorTotal += quantCinquenta * 0.50
valorTotal += quantUmReal

print("Arthur voce tem R$ {:.2f}".format(valorTotal))
