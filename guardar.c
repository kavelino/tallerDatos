#include <stdio.h>
#include "./validar.h"
#include "./guardar.h"

void guardar(Usuario_t *user, int tamanio) {
	FILE *archivo;
	archivo = fopen("usuario.txt", "wt");

	for(int i = 0; i < tamanio; i++) {
		fprintf(archivo,"%s", user[i].nombre);
		fprintf(archivo,"\t%s", user[i].apellido);
		fprintf(archivo,"\t%s", user[i].username);
		fprintf(archivo,"\t%s", user[i].password);
		fprintf(archivo,"\t%d\n", user[i].userid);
	}

	fclose(archivo);
}
