
class Aluno:
    def __init__(self, nome):
        self._nome = nome
        self._notas = []
        self._media = 0

    def PreencheNotas(self, notas):
        self._notas = notas

    def CalculaMedia(self):
        self._media = sum(self._notas)/len(self._notas)

    def GetMedia(self):
        return self._media

    def GetNome(self):
        return self._nome

alunos = []

def DesejaContinuar():
    resposta = input('Deseja continuar? [s]im/[n]ao: ')
    return resposta == 's'

def LeNomeAlunos():
    continuar = True
    while continuar:
        nome = input('Digite o nome do aluno: ')
        aluno = Aluno(nome)
        alunos.append(aluno)
        continuar = DesejaContinuar()

def LeNotasAlunos():
    for aluno in alunos:
        print('\n\n')
        print('Digite as notas do aluno ' + aluno.GetNome())
        notas = []
        for i in range(4):
            nota = float(input('Digite a nota ' + str(i+1) + ' : '))
            notas.append(nota)
        aluno.PreencheNotas(notas)
        aluno.CalculaMedia()

def ImprimeAlunos():
    for aluno in alunos:
        print('{nome} - {media:.1f}'.format(nome=aluno.GetNome(),
                                            media=aluno.GetMedia()))

def main():
    LeNomeAlunos()
    LeNotasAlunos()
    alunos.sort(key=lambda aluno: aluno.GetMedia(), reverse=True)
    ImprimeAlunos()

main()



















