import os
votacao = {19: {'nome': 'Leonardo',
                'quantidade': 0},
           27: {'nome': 'Luizinho',
                'quantidade': 0},
           33: {'nome': 'Alfredo',
                'quantidade': 0},
           42: {'nome': 'Eymael',
                'quantidade': 0},
           500: {'nome': 'Branco',
                 'quantidade': 0}}

votosNulos = 0
votosTotais = 0

def ImprimeMenu():
    print('---------------------------------------------------')
    print('        Sistema de eleições presidenciais          ')
    print('---------------------------------------------------')
    print('Vote em um dos candidatos: ')
    print('   19 - Leonardo')
    print('   27 - Luizinho')
    print('   33 - Alfredo')
    print('   42 - Eymael')
    print('  500 - Voto em Branco')
    print('---------------------------------------------------')

def ConfirmaVoto(numeroVotado):
    if numeroVotado in votacao.keys():
        nome = votacao[numeroVotado]['nome']
        print('O seu voto é no candidato: {}'.format(nome))
    else:
        print('Candidato invalido!')
    confirmacao = input('Deseja confirmar? [s]im/[n]ao: ')
    return confirmacao == 's'

def ContabilizaVoto(numeroVotado):
    global votosTotais, votosNulos
    votosTotais += 1
    if numeroVotado in votacao.keys():
        votacao[numeroVotado]['quantidade'] += 1
    else:
        votosNulos += 1

def ImprimeRelatorioEleicao():
    if votosTotais > 0:
        votosBrancos = votacao[500]['quantidade']
        votosInvalidos = votosBrancos + votosNulos
        votosValidos = votosTotais - votosInvalidos
        os.system("cls")
        print("--------------------------------------")
        print("     Votos validos por candidato")
        print("--------------------------------------")
        for numero, candidato in votacao.items():
            if numero != 500:
                nome = candidato['nome']
                quant = candidato['quantidade']
                porc = quant*100/votosValidos
                msg = "{nome} - {votos} - {porc:.2f}%".format(nome=nome,
                                                              votos=quant,
                                                              porc=porc)
                print(msg)

        porcBrancos = votosBrancos*100/votosTotais
        porcNulos = votosNulos*100/votosTotais
        print("--------------------------------------")
        print('Votos Brancos: {quant} - {porc:.2f}%'.format(quant=votosBrancos,
                                                           porc=porcBrancos))
        print('Votos Nulos: {quant} - {porc:.2f}%'.format(quant=votosNulos,
                                                     porc=porcNulos))

def LeVotoEleitor():
    votacaoEmAndamento = True
    numeroVotado = 0
    while votacaoEmAndamento:
        os.system("cls")
        ImprimeMenu()
        numeroVotado = int(input('Digite o numero do candidato: '))
        votoConfirmado = ConfirmaVoto(numeroVotado) if numeroVotado != 0 else True
        votacaoEmAndamento = not votoConfirmado
    return numeroVotado



def main():
    continuaVotacao = True
    while continuaVotacao:
        numeroVotado = LeVotoEleitor()
        continuaVotacao = numeroVotado != 0
        if continuaVotacao:
            ContabilizaVoto(numeroVotado)
            print('Voto contabilizado!')
            input('Pressione ENTER para finalizar!')

    ImprimeRelatorioEleicao()

main()