nota1 = float(input('Digite a primeira nota: '))
nota2 = float(input('Digite a segunda nota: '))
nota3 = float(input('Digite a terceira nota: '))
nota4 = float(input('Digite a quarta nota: '))

media = (nota1 + nota2 + nota3 + nota4) / 4
print('A media do aluno é {:.2f}'.format(media))
if media >= 6.0:
    print('APROVADO!')
else:
    print('REPROVADO!')
