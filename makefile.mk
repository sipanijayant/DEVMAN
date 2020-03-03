cproject.out : cminiproject.o ui.o 
	gcc cminiproject.o ui.o  -o cproject.out -lm
cminiproject.o : cminiproject.c 
	gcc -c cminiproject.c -lm
ui.o : ui.c 
	gcc -c ui.c -lm

