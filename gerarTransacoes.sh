#!/bin/bash
#Vamos *tentar* imprimir acentos..
export LANG=pt_BR

#Informações nescessárias:

#quantos itens devem ser criados
#quantas transacoes
#quantos acessos por transação
#nome do arquivo para salvar

if ! [ -f ./mktasks.py ]
then
    echo "Script mktasks.py não existe.. encontre-o !"
    exit 0
fi

if [ $# != 0 ]
then
    nDados=$1
    nTrans=$2
    nAcess=$3
    arquivo=$4
else
    
    echo "Quantos itens de Dados serão utilizados ?"
    read  nDados

    echo "Quantas trasações ocorrerão ?"
    read  nTrans

    echo "Quantos Acessos ocorrerão ?"
    read  nAcess

    echo "Qual o nome do arquivo que salvará as transaçoes ?"
    read  arquivo
fi

python3 ./mktasks.py $nDados $nTrans $nAcess > "$arquivo"
