/usr/local/Cellar/bison/3.8.2/bin/bison -d tiny.y
 flex tiny.l
 gcc -c *.c
 gcc -o tiny *.o -ly -lfl
