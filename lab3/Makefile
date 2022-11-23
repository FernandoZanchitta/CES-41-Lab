all:
	flex cminus.l
	bison -d cminus.y
	gcc -c *.c
	gcc -o build/cminus *.o -ll
	rm *.o *.tab.* *.yy.*
run:
	./build/cminus test/teste_example.c && cat test/teste_example.tm
clear:
	rm *.o *.tab.* *.yy.*