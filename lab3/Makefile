all:
	flex tiny.l
	bison -d tiny.y
	gcc -c *.c
	gcc -o build/tiny *.o -ly -ll
run:
	./build/tiny test/ex.c
clear:
	rm *.o *.tab.* *.yy.*