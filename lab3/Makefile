all:
	flex tiny.l
	bison -d tiny.y
	gcc -c *.c
	mkdir -p build
	gcc -o build/tiny *.o -lfl
	rm *.o *.tab.* *.yy.*
run:
	./build/tiny test/ex.c
clear:
	rm *.o *.tab.* *.yy.*