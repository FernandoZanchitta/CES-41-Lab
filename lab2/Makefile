all:
	bison -d tiny.y
	flex tiny.l
	gcc -c *.c  
	mkdir -p build
	gcc -o build/tiny *.o -ll
clear:
	rm *.o *.tab.* *.yy.*