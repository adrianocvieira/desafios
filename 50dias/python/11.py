def OperacaoEhValida(operacao):
    return operacao == '+' or operacao == "-" \
           or operacao == '*' or operacao == '/'

def LeiaOperacaoMatematicaValida():
    operacao = ''
    while not OperacaoEhValida(operacao):
        operacao = input('Digite a operacao (+,-,*,/): ')
    return operacao

valor1 = float(input('Digite o primeiro valor: '))
operacao = LeiaOperacaoMatematicaValida()
valor2 = float(input('Digite o segundo valor: '))

resultado = 0
if operacao == '+':
    resultado = valor1 + valor2
elif operacao == '-':
    resultado = valor1 - valor2
elif operacao == '*':
    resultado = valor1 * valor2
elif operacao == '/':
    if valor2 != 0:
        resultado = valor1 / valor2
    else:
        print('ERRO MATEMATICO: DIVISAO POR ZERO!')

print('Resultado da operacao é {res}'.format(res=resultado))
