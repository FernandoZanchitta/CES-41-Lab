all:
	bison -d tiny.y
	flex tiny.l
	gcc -c *.c  
	mkdir -p build
	gcc -o build/tiny *.o -ll
	rm *.o *.tab.* *.yy.*
clear:
	rm *.o *.tab.* *.yy.*