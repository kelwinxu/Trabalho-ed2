@echo on
gcc main.c funcoes.c -o meu_programa.exe
echo Teste automatico
meu_programa.exe
echo Teste com vetores 
meu_programa.exe 8,8,6,5,5,5,3,2,1 desc 5,8,7

cmd/k