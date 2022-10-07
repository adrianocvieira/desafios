import random
import os

PONTUACAO_BASE = 3

placar = 0
mult_pontos = 1
multiplicando = 0
multiplicador = 0

def InicializaPlacar():
    global mult_pontos, placar
    mult_pontos = 1
    placar = 0

def AtualizaPontos(nivel):
    global mult_pontos, placar
    placar += mult_pontos * PONTUACAO_BASE
    if (nivel % 5) == 0:
        mult_pontos += 1

def GeraNumeroEntre1e10():
    return random.randint(1, 10)

def EfetuaQuestao():
    resposta = int(input(str(multiplicando) + 'x'+str(multiplicador)+' = '))
    return resposta == multiplicando*multiplicador

def ImprimeCabecalho(nivel):
    os.system('cls')
    cabecalho = "---------------------------------------------------------\n" \
                " Nivel: " + str(nivel) +"   |   Placar: " + str(placar) + \
                "   |   Multiplicador: " + str(mult_pontos) + "\n"\
                "---------------------------------------------------------\n"
    cabecalho.format(nivel=nivel,
                     placar=placar,
                     mult=mult_pontos)
    print(cabecalho)

def EfetuaQuestoes():
    global multiplicando, multiplicador
    nivel = 0
    continuar = True
    while continuar:
        nivel += 1
        multiplicando = GeraNumeroEntre1e10()
        multiplicador = GeraNumeroEntre1e10()

        ImprimeCabecalho(nivel)
        continuar = EfetuaQuestao()
        if continuar:
            AtualizaPontos(nivel)


def UsuarioErrou():
    print('Infelizmente voce errou!\n')
    print('O resultado de {prim}x{sec} = {ter}'.format(prim=multiplicando,
                                                       sec=multiplicador,
                                                       ter=multiplicando*multiplicador))
    print('\n\n')

def UsuarioQuerContinuar():
    tentar = input('Voce quer tentar novamente? [s]im/[n]ao: ')
    return tentar == 's'

def main():
    continuar = True

    while continuar:
        InicializaPlacar()
        EfetuaQuestoes()
        UsuarioErrou()
        continuar = UsuarioQuerContinuar()


main()