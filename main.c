#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "./validar.h"

void crearUsuario(Usuario_t *);
void crearPassWord(Usuario_t *);

int main() {
	Usuario_t user;
	int opcion = 1;
	while(opcion) {		
		printf("\nIngresar usuario (1) o ");
		printf("Salir (2): ");
		scanf("%d", &opcion);
	
		
		switch(opcion) {
			case 1:
				printf("Ingrese su nombre: ");
				scanf("%s", user.nombre);
				user.nombre[0] = toupper(user.nombre[0]);
				printf("Ingrese su apellido: ");
				scanf("%s", user.apellido);
				user.apellido[0] = toupper(user.apellido[0]);
				crearUsuario(&user);
				crearPassWord(&user);
				user.userid = 10000 + rand() % (99999 - 10000);

				printf("\nNombre: %s %s\n", user.nombre, user.apellido);
				printf("Usuario: %s\n", user.username);
				printf("Password: %s\n", user.password);
				printf("UserId: %d\n", user.userid);
				opcion = 1;
				break;
			case 2:
				printf("Saliendo...\n");
				opcion = 0;
				break;
		}
	}
	
	
}

void crearUsuario(Usuario_t *user) {
	user->username[0] = tolower(user->nombre[0]);

	for(int i = 1; i < MAXSTR; i++) {
		if(user->apellido[i] != 0) {
			user->username[i] = tolower(user->apellido[i]);
		}
		else {
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
				printf("Password aceptado\n");
    				boolean = 0;
    				break;
			case 3:
				printf("Password tiene menos de 10 caracteres\n");
    				boolean = 1;
    				break;

			case 4:
				printf("Password no contiene letras\n");
    				boolean = 1;
    				break;
			case 5:
				printf("Password no contiene digitos\n");
				boolean = 1;
				break;
			default:
				boolean = 1;
				break;
		}
	}
}
