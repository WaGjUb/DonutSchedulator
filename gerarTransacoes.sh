#!/bin/bash
#Vamos *tentar* imprimir acentos..
export LANG=pt_BR

#Informa��es nescess�rias:

#quantos itens devem ser criados
#quantas transacoes
#quantos acessos por transa��o
#nome do arquivo para salvar

if ! [ -f ./mktasks.py ]
then
    echo "Script mktasks.py n�o existe.. encontre-o !"
    exit 0
fi

if [ $# != 0 ]
then
    nDados=$1
    nTrans=$2
    nAcess=$3
    arquivo=$4
else
    
    echo "Quantos itens de Dados ser�o utilizados ?"
    read  nDados

    echo "Quantas trasa��es ocorrer�o ?"
    read  nTrans

    echo "Quantos Acessos ocorrer�o ?"
    read  nAcess

    echo "Qual o nome do arquivo que salvar� as transa�oes ?"
    read  arquivo
fi

python3 ./mktasks.py $nDados $nTrans $nAcess > "$arquivo"
