salarioInicial = float(input('Digite o salario inicial: R$ '))
anoContratacao = int(input('Digite o ano de contratacao: '))
anoFinal = int(input('Digite o ano que voce quer saber o salario: '))
diferencaAnos = anoFinal - anoContratacao

porcentagem_aumento = 0.015
proporcao_aumento_taxa_anual = 0.10
salario = salarioInicial
for i in range(diferencaAnos):
    salario += salario*porcentagem_aumento
    porcentagem_aumento += porcentagem_aumento*proporcao_aumento_taxa_anual

print('O salario do funcionario em {ano} sera R$ {valor:.2f}'.format(ano=anoFinal,
                                                                     valor=salario))
