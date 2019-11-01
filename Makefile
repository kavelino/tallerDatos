usuarios: main.o validar.o
	gcc main.o validar.o -o usuarios

main.o: main.c validar.h guardar.h
	gcc -Wall -c main.c -o main.o

validar.o: validar.c validar.h
	gcc -Wall -c validar.c -o validar.o

guardar.o: guardar.c guardar.h
	gcc -Wall -c guardar.c -o guardar.o

.PHONY: clean

clean:
	rm *.o usuarios
