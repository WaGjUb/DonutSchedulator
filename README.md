# DonutSchedulator
APS de BD2  gerador de schedules 
---
###Como Utilizar
Basta fazer uso os scripts "wrappers" feitos em Shell. Para tanto, mude a configuração dos scripts para executavel (se nescessário) e rode-os. Eles devem ser auto explicativos perguntando sobre os dados nescessários.
###Alternativamente
Você pode passar os parâmetros para os scripts .sh diretamente. Segundo a ordem demonstrada na apresentação do projeto.

###Executar o gerenciador
Deve rodar o make no diretorio raiz para compilar o código, o arquivo DonutSchedulator.out será gerado, execute ./DonutSchedulator.out 'nome do arquivo do schedule' sem os apostrofos. Por exemplo ./DonutSchedulator.out tests/t4

###Saída
Se tudo ocorrer bem, o arquivo saida.txt será criado, e dentro dele haveŕa um schedule usando o 2PL ou as transações que estão em DeadLock


