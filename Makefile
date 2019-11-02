usuarios: main.o validar.o guardar.o
	gcc main.o validar.o guardar.o -o usuarios

main.o: main.c validar.h guardar.h
	gcc -Wall -c main.c -o main.o

validar.o: validar.c
	gcc -Wall -c validar.c -o validar.o

guardar.o: guardar.c
	gcc -Wall -c guardar.c -o guardar.o

.PHONY: clean

clean:
	rm *.o usuarios
