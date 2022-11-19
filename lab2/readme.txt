/usr/local/Cellar/bison/3.8.2/bin/bison -d tiny.y
 flex tiny.l
 gcc -c *.c
 gcc -o tiny *.o -ly -lfl

Removendo -ly e deixando só -lfl funcionou

- Rodar casos de teste
./build/tiny test/ex.c