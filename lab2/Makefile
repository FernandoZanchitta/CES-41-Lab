all:
	bison -d tiny.y
	flex tiny.l
	gcc -c *.c  
	mkdir -p build
	gcc -o build/tiny *.o -lfl
	make clear
clear:
	rm *.o *.tab.* *.yy.*