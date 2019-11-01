#include <stdio.h>
#include "./validar.h"
#include "./guardar.h"

void guardar(Usuario_t *user, int tamanio) {
	FILE *archivo;
	archivo = fopen("usuario.txt", "wt");
	
	for(int i = 0; i < tamanio; i++) {
		fprintf(archivo,"%s\t", user[i].nombre);
		fprintf(archivo,"%s\t", user[i].apellido);
		fprintf(archivo,"%s\t", user[i].username);
		fprintf(archivo,"%s\t", user[i].password);
		fprintf(archivo,"%d\n", user[i].userid);
	}

	fclose(archivo);
}
