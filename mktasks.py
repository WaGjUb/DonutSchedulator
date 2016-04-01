import sys
import random as rd

###Variaveis globais###

#Alfabeto. Nao tem R e W por que sao os nomes de acoes
# R Read() e W Write()
alfabeto = "ABCDEFGHIJKLMNOPQSTUVXYZ"
acoes    = "RW"

#Verifica se existem os 4 parametros esperados
def checarParametros():
    if len( sys.argv ) < 4:
        print( "parametros invalidos" )
        sys.exit( 1 )

#Escreve na tela cada transacao
def mkTansacao( nomeTransacao, Dados, nAcoes ):

    #inicio da transacao
    print( "S" + str(nomeTransacao), end="; " )
    
    #acessos da transacao
    for i in range( nAcoes ):
        print( rd.choice(acoes)+ str(nomeTransacao)+"("+rd.choice(Dados)+")", end="; " )

    #fim da trasacao
    print("E"+str(nomeTransacao), end=";\n" )


if __name__ == "__main__" :
    checarParametros()

    #Numero de Dados
    nDados = int(sys.argv[1])
    #Numero de transacoes
    nTrans = int(sys.argv[2])
    #Numero de acessos
    nAcesso = int(sys.argv[3])

    #Lista de Dados
    Dados = alfabeto[:nDados]
    print( Dados )

    for i in range( nTrans ):
        print("T"+str(i)+":", end=" ")
        mkTansacao( i, Dados, nAcesso )
    
    
