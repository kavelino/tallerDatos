#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "./validar.h"

int validar(Usuario_t *user) {
	if(strlen(user->password) < 10) {
		return 3;
	}

	int contChar = 0;
	int contNum = 0;

	for(int i=0; i<strlen(user->password); i++) {
		char tmp = user->password[i];
		if(isalpha(tmp)) {
			contChar++;
		}
		else {
			contNum++;
		}
	}

	if(contChar == 0) {
		return 4;
	}

	if(contNum == 0) {
		return 5;
	}

	return 0;
}

