
MEGABYTE = 1024*1024
usuarios = {}

def LeTextoDoArquivo(nomeDoArquivo):
    input_file = open(nomeDoArquivo, 'r')
    texto = input_file.read()
    input_file.close()
    return texto


def EscreveTextoNoArquivo(texto, nomeDoArquivo):
    output_file = open(nomeDoArquivo, 'w')
    output_file.write(texto)
    output_file.close()

def PreencheInformacoesUsuarios(texto):
    linhas = texto.split('\n')
    for linha in linhas:
        linhaEmLista = linha.split()
        nomeUsuario = linhaEmLista[0]
        espacoUtilizado = int(linhaEmLista[1])
        usuarios[nomeUsuario] = espacoUtilizado

def CalculaEspacoTotal():
    espacosUtilizados = [espacoDoUsuario for _, espacoDoUsuario in usuarios.items()]
    espacoTotal = sum(espacosUtilizados)
    return espacoTotal

def ConverteBytesParaMegabytes(espacoEmBytes):
    return espacoEmBytes / MEGABYTE

def CriaRelatorio():
    quantidadeUsuarios = 0
    espacoTotal = CalculaEspacoTotal()

    relatorio = 'ACME Inc.    Uso do espaço em disco pelos usuários\n'
    relatorio += '----------------------------------------------------\n'
    relatorio += 'Nr.  Usuário        Espaço utilizado     % do uso\n'

    numero=1
    for nomeUsuario, espacoDoUsuario in usuarios.items():
        espacoEmMB = ConverteBytesParaMegabytes(espacoDoUsuario)
        porcentagem = espacoDoUsuario*100/espacoTotal

        textoNumero = str(numero).ljust(5)
        textoNome = nomeUsuario.ljust(14)
        textoEspaco = "{:.2f}".format(espacoEmMB).rjust(7) + " MB"
        textoEspaco += " ".ljust(11)
        textoPorc = "{:.2f}".format(porcentagem).rjust(6) + "%"

        linha = "{num}{usuario}{espaco}{porc}\n".format(num=textoNumero,
                                                        usuario=textoNome,
                                                        espaco=textoEspaco,
                                                        porc=textoPorc)
        relatorio += linha
        quantidadeUsuarios += 1
        numero += 1

    espacoTotalEmMB = ConverteBytesParaMegabytes(espacoTotal)
    relatorio += "\nEspaco total ocupado: {:.2f} MB".format(espacoTotalEmMB)
    relatorio += "\nEspaco médio ocupado: {:.2f} MB".format(espacoTotalEmMB / quantidadeUsuarios)
    return relatorio


def main():
    texto = LeTextoDoArquivo('usuarios.txt')
    PreencheInformacoesUsuarios(texto)

    relatorio = CriaRelatorio()
    EscreveTextoNoArquivo(relatorio, 'relatorio.txt')

main()





















