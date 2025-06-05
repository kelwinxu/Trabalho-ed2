@echo on
REM == Comentario em bat REM
REM Se for executar em algum pc da USP tirar esses "REM" para execução REM
REM set PATH=%PATH%;C:\Program Files\CodeBlocks\MinGW\bin REM
REM gcc --version REM
REM ------------Tirar até aqui------------REM

REM esse é o comando para executar via cmd consequentimente via .bat REM
REM renomie para seu main para seu outro .c e de um nome aleatorio para seu programa, pode ser qualquer um REM

gcc main.c funcoes.c -o meu_programa.exe
REM depois esse comando para executar seu codigo REM
meu_programa.exe
REM Se o programa tiver leitura por parte do usuario tipo um scanf então seria assim: REM
REM meu_programa.exe 8, sendo 8 o valor a ser lido pelo scanf por exemplo REM

REM Opicional caso queria manter o cmd abetrto depois da execução REM
cmd/k