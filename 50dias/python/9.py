mensagem = "Digite o numero de dias trabalhados pelo funcionario: "
numero_dias_trabalhados = -1
while numero_dias_trabalhados <= 0:
    numero_dias_trabalhados = int(input(mensagem))

anos = 0
while (numero_dias_trabalhados - 365) >= 0:
    numero_dias_trabalhados = numero_dias_trabalhados - 365
    anos = anos + 1

meses = 0
while (numero_dias_trabalhados - 30) >= 0:
    numero_dias_trabalhados = numero_dias_trabalhados - 30
    meses = meses + 1

mensagem = "O funcionario trabalhou {a} anos, {m} meses e {d} dias."
print(mensagem.format(a=anos, m=meses, d=numero_dias_trabalhados))
