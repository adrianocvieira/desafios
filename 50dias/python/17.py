def LeiaNumeroPositivo(mensagem):
    valor = -1
    while valor <= 0:
        valor = int(input(mensagem))
    return valor

nomeFuncionario = input('Digite o nome do funcionario: ')
horasTrabalhadas = LeiaNumeroPositivo('Digite os dias trabalhados: ')
numeroDependentes = LeiaNumeroPositivo('Quantos dependentes: ')

salarioBruto = 23.00 * horasTrabalhadas + 34.00 * numeroDependentes

IR = 0.15 * salarioBruto
INSS = 0.085 * salarioBruto

salarioLiquido = salarioBruto - IR - INSS

print('--------------------------------------------------')
print('Nome: {nome}'.format(nome=nomeFuncionario))
print('Horas trabalhadas: {horas}'.format(horas=horasTrabalhadas))
print('Dependentes: {dep}'.format(dep=numeroDependentes))
print('--------------------------------------------------')
print('Salario Bruto: {:.2f}'.format(salarioBruto))
print('Descontos:')
print('   IR: {:.2f}'.format(IR))
print('   INSS: {:.2f}'.format(INSS))
print('Salario Liquido: {:.2f}'.format(salarioLiquido))
