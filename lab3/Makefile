all:
	flex cminus.l
	bison -d cminus.y
	gcc -c *.c
	gcc -o build/cminus *.o -ly -ll
	rm *.o *.tab.* *.yy.*
run:
	./build/cminus test/ex.c
clear:
	rm *.o *.tab.* *.yy.*