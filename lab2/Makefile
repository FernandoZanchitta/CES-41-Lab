all:
	bison -d tiny.y
	flex tiny.l
	gcc -c *.c  
	gcc -o tiny *.o -lfl
clear:
	rm *.o *.tab.* *.yy.*