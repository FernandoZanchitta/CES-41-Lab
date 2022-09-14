No prompt:

$ flex lexical.l
$ gcc -c *.c
$ gcc -o lexical *.o -lfl

(Em Mac pode ser que funcione com -ll no lugar de -lfl)

Executavel gerado:

$ ./lexical test/teste_ordMatrix.c
$ ./lexical test/teste_sortArrays.c 