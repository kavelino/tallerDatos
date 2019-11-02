#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "./validar.h"
#include "./guardar.h"

void crearUsuario(Usuario_t *);
void crearPassWord(Usuario_t *);
int esDigito(char buf[]);

int main() {
	Usuario_t user[MAX];
     	int tamanio = 0;
     	char buf[2];
     	int opcion = 0;
     	int bandera = 1;
	int tmp = 1;

     	while(bandera) {
		
		do {	
			printf("\nIngresar usuario (1) o ");
	     		printf("Salir (2): ");
	     		scanf("%s", buf);
	     		tmp = esDigito(buf);
		}while(tmp == 0);

       	     	opcion = atoi(buf);
		switch(opcion) {
		     	case 1:
				printf("Ingrese su nombre: ");
				scanf("%s", user[tamanio].nombre);
				user[tamanio].nombre[0] = toupper(user[tamanio].nombre[0]);
				printf("Ingrese su apellido: ");
				scanf("%s", user[tamanio].apellido);
				user[tamanio].apellido[0] = toupper(user[tamanio].apellido[0]);
				crearUsuario(&user[tamanio]);
				crearPassWord(&user[tamanio]);
				user[tamanio].userid = 10000 + rand() % (99999 - 10000);
				
				tamanio++;
				bandera = 1;
				break;
		     	case 2:
				bandera = 0;
				break;
		     	default:
				bandera = 1;
				break;
		}
	}
	
	guardar(user, tamanio);
	printf("Saliendo...\n");
}

void crearUsuario(Usuario_t *user) {
	user->username[0] = tolower(user->nombre[0]);

	for(int i = 1; i < MAXSTR; i++) {
		if(user->apellido[i-1] != 0) {
			user->username[i] = tolower(user->apellido[i-1]);
		}
		else {
			user->username[i] = '\0';
			break;
		}
	}
}

void crearPassWord(Usuario_t *user) {
	int boolean = 1;

	while(boolean) {
		printf("Ingrese un password: ");
		scanf("%s", user->password);
		int tmp = validar(user);

		switch(tmp) {
			case 0:
				fprintf(stderr, "Password aceptado\n");
    				boolean = 0;
    				break;
			case 3:
				fprintf(stderr, "Password tiene menos de 10 caracteres\n");
    				boolean = 1;
    				break;

			case 4:
				fprintf(stderr, "Password no contiene letras\n");
    				boolean = 1;
    				break;
			case 5:
				fprintf(stderr, "Password no contiene digitos\n");
				boolean = 1;
				break;
			default:
				boolean = 1;
				break;
		}
	}
}

int esDigito(char buf[]) {
	for(int i = 0; i < strlen(buf); i++) {
        	if(!(isdigit(buf[i]))) {
            		return 0;
        	}
    	}
    return 1;
}