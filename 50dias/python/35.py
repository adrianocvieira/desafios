




from itertools import combinations
nomeDosAlunos = []

def LeNomeDosAlunos():
    quantidade = int(input('Quantos alunos você tem? '))

    for i in range(quantidade):
        mensagem = 'Digite o nome do aluno ' + str(i+1) + ": "
        nome = input(mensagem)
        nomeDosAlunos.append(nome)

def CriaPossiveisGrupos():
    comb = combinations(nomeDosAlunos, 2)
    return comb

def main():
    LeNomeDosAlunos()
    possiveisGrupos = CriaPossiveisGrupos()

    for grupo in list(possiveisGrupos):
        print(grupo)

main()