all: analex anasin

compiler.o: compiler.c include/compiler.h
	gcc -Wall -I ./include -c compiler.c

analex.o: analex.c include/compiler.h
	gcc -Wall -I ./include -c analex.c

anasin.o: anasin.c include/compiler.h
	gcc -Wall -Wno-missing-braces -I ./include -c anasin.c

analex: analex.o compiler.o
	gcc -Wall analex.o compiler.o -o analex
	
anasin: anasin.o compiler.o
	gcc -Wall -Wno-missing-braces anasin.o compiler.o -o anasin

clean:
	rm *.o anasin analex
