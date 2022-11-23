all:
	flex tiny.l
	bison -d tiny.y
	gcc -c *.c
	gcc -o build/tiny *.o -ly -ll
run:
	./build/tiny test/ex.c
	
run_show_code_gen:
	./build/tiny test/ex.c && cat test/ex.tm
clear:
	rm *.o *.tab.* *.yy.*