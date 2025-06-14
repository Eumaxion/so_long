#!/bin/bash

#gcc -o validador ./so_long/main.c

#test 1: nenhum argumento

if [ ! -f main.out ]; then
    echo "main.out nao criado"
    exit 1
fi

./main.out > /dev/null 2>&1
if [ $? -ne 0 ] ; then
    echo "teste 1 ok (sem argumento)"
else
    echo "Teste 1 Falhou"
fi

#teste 2: argumento sem .ber
./main.out  arquivo.csv > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Teste 2 ok (extensao invalida)"
else
    echo "Teste 2 falhou"
fi

# Teste 3: arquivo com .ber
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 4: mais de 1 argumento
./main.out a.ber b.ber > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "Teste 4 ok (argumentos demais)"
else
    echo "Teste 4 falhou"
fi

# Teste 5: map sem exit
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 6: map com mais de 1 exit
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 7: map sem player
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 8: map com mais de 1 player
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 5: map sem exit
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi

# Teste 5: map sem colectables
./main.out map.ber > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Teste 3 ok (arquivo valido)"
else
    echo "Teste 3 falhou"
fi