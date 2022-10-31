def leia_valor_positivo(mensagem):
    valor = -1
    while valor <= 0:
        valor = float(input(mensagem))
    return valor

peso = leia_valor_positivo("Digite o seu peso (kg): ")
altura = leia_valor_positivo("Digite a sua altura (m): ")
imc = peso / (altura**2)

mensagem = ""
if imc < 18.5:
    mensagem = "Magreza"
elif 18.5 <= imc < 25.0:
    mensagem = "Normal"
elif 25.0 <= imc < 30.0:
    mensagem = "Sobrepeso"
elif 30.0 <= imc < 40.0:
    mensagem = "Obesidade"
else:
    mensagem = "Obesidade Grave"

print('O valor do IMC calculado é {:.2f}'.format(imc))
print('Sua categoria de IMC é: ' + mensagem)