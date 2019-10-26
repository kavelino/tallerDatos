#include <stdio.h>
#include <ctype.h>
#include "./validar.h"

void crearUsuario(Usuario_t *);
void crearPassWord(Usuario_t *);

int main() {
	Usuario_t user;
	printf("Ingrese su nombre: ");
	scanf("%s", user.nombre);
	user->nombre[0] = toupper(user->nombre[0]);
	printf("Ingrese su apellido: ");
	scanf("%s", user.apellido);
	user->apellido[0] = toupper(user->apellido[0]);
	crearUsuario(&user);
	crearPassWord(&user);
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
	printf("Usuario sugerido: %s", user->username);
}

void crearPassWord(Usuario_t *user) {
	int boolean = 1;

	while(tmp) {
		printf("Ingrese un password: ")
		scanf("%s", user.password);
		int tmp = validar(&user); 
}


}