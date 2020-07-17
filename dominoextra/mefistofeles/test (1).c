// Este fichero se le da al alumno
#include <stdio.h>
#include "azar.h"
#include "colores.h"
#include "preguntas.h"
#include "duerme.h"

#define MAX		10

int main() {
	int i,n, nums;

	inicializar_azar();
	nums = preguntar_n_en_rango("Cuantos numeros al azar quieres?", 0, MAX);
	for(i=0;i<nums;i++) {
		n = numero_al_azar(MAX);
		printf("%d: ", i);
		printf_color(n);
		printf("%d\n", n);
		printf_reset_color();
		// duerme_un_rato();
		duerme_un_nano_rato();
	}

	return 0;
}

