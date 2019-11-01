ejecutable: main.o validar.o
	gcc main.o validar.o -o ejecutable

main.o: main.c validar.h
	gcc -Wall -c main.c -o main.o

validar.o: validar.c validar.h
	gcc -Wall -c validar.c -o validar.o

#guardar.o: guardar.c
	#gcc -Wall -c guardar.c -o guardar.o

.PHONY: clean

clean:
	rm *.o ejecutable
