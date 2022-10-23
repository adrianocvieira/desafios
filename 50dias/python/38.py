
def DesejaContinuar():
    continuar = input('Deseja continuar? [s]im/[n]ao: ')
    return continuar == "s"

def EhBissexto(ano):
    divisivelPor4 = (ano % 4) == 0
    divisivelPor100 = (ano % 100) == 0
    divisivelPor400 = (ano % 400) == 0

    divisivelPor4ENaoPor100 = divisivelPor4 and not divisivelPor100
    divisivelPorTudo = divisivelPor4 and \
                       divisivelPor100 and \
                       divisivelPor400
    return divisivelPor4ENaoPor100 or divisivelPorTudo

def ImprimeResultado(ano, ehBissexto):
    msg = "O ano {ano}{nao} e bissexto!".format(ano=ano,
                                                nao=" nao" if not ehBissexto else "")
    print(msg)

def main():
    continuar = True
    while continuar:
        ano = int(input('Digite um ano: '))

        ImprimeResultado(ano, EhBissexto(ano))
        continuar = DesejaContinuar()

main()