all:
	flex tiny.l
	bison -d tiny.y
	gcc -c *.c
	gcc -o tiny *.o -ly -ll
run:
	./tiny teste.tny
clear:
	rm *.o *.tab.* *.yy.*