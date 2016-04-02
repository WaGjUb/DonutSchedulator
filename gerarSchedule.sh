#!/bin/bash

#informacoes nescessarias.. 
#arquivo de entrada..
#onde salvar o shcedule

if ! [ -f ./mkschedule.py ]
then 
	echo "Script mkschedule.py não foi encontrado.. ache-o !"
	exit 0
fi

if [ $# -eq 2 ]
then 
	transacoes=$1
	arquivo=$2
else
	echo "Qual o arquivo que tem as transacoes ?"
	read transacoes

	echo "Onde salvar o schedule ?"
	read arquivo
fi

cat "$transacoes" | python3 ./mkschedule.py > "$arquivo"
