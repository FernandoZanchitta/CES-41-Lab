all:
	flex cminus.l
	bison -d cminus.y
	gcc -c *.c
<<<<<<< HEAD
	gcc -o build/cminus *.o -ly -ll
=======
	mkdir -p build
	gcc -o build/tiny *.o -lfl
>>>>>>> 8df9adf16446663f453c91d474b86f8191172f53
	rm *.o *.tab.* *.yy.*
run:
	./build/cminus test/ex.c
clear:
	rm *.o *.tab.* *.yy.*