def leia_valor_cateto_positivo(nome_cateto):
    mensagem = 'Digite o valor do cateto ' + nome_cateto + ": "
    valor_cateto = -1
    while valor_cateto <= 0:
        valor_cateto = float(input(mensagem))
    return valor_cateto

a = leia_valor_cateto_positivo("a")
b = leia_valor_cateto_positivo("b")

soma_quadrado_catetos = a**2 + b**2
h = soma_quadrado_catetos**(1/2)
print('O valor da hipotenusa do triangulo retangulo é ' + str(h))
