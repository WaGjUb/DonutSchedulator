import random as rd
#Lê todas as linhas na memoria a partir do stdout
transacoes = [ ]
#i = 0
print(input())
try:
    while True:
 #       print( input(), i );
      #  i = i+1
        transacoes.append( input().split(" ") )
except EOFError:
    #remove o identificador da transacao
    transacoes = [ i[1:] for i in transacoes]#soa estranho, eu sei
                                            #procure por List Comprehensions
                                            #para entender melhor
    pass

#Aqui comeca a criacao da schedule
#transacao = transacoes[0]
#transacoes.remove( transacao )
while len(transacoes):
    transacao = rd.choice( transacoes )     #sorteia uma transacao
    if len(transacao):
        print( transacao.pop(0), end=" " )  #imprime e remove o elmen. 0
    else:
        transacoes.remove( transacao )      #se a transacao for nula, remove ela

#quebra a linha... º-º
print()
