import random

def GeraNumeroEntre1e10():
    return random.randint(1,10)

def EfetuaQuestao(multiplicando, multiplicador):
    resposta = int(input(str(multiplicando) + 'x'+str(multiplicador)+' = '))
    return resposta == multiplicando*multiplicador

def UsuarioErrou(multiplicando, multiplicador):
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
        while continuar:
            multiplicando = GeraNumeroEntre1e10()
            multiplicador = GeraNumeroEntre1e10()

            continuar = EfetuaQuestao(multiplicando, multiplicador)

        UsuarioErrou(multiplicando, multiplicador)
        continuar = UsuarioQuerContinuar()


main()