all:
	flex tiny.l
	bison -d tiny.y
	mkdir -p build
	gcc -c *.c
	gcc -o build/tiny *.o -lfl
	rm *.o *.tab.* *.yy.*
run:
	./build/tiny test/ex.c
	
run_show_code_gen:
	./build/tiny test/ex.c && cat test/ex.tm
clear:
	rm *.o *.tab.* *.yy.*