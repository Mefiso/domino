#include "partida.h"
#include <stdio.h>
void mostrar_mesa_dosde(tmesa mesa){
	int m,j;
	printf("\n");
	for (m=0; m<3; m++){
		for(j=0; j<mesa.num; j++)
		{
			if(m==0 && mesa.mesa[j].i == mesa.mesa[j].d)
				printf("%d|", mesa.mesa[j].i);
			else if(m==0 && mesa.mesa[j].i != mesa.mesa[j].d){
				printf("___ ");
			}
			else if(m==1 && mesa.mesa[j].i == mesa.mesa[j].d){
				printf("-|");
			}
			else if(m==1 && mesa.mesa[j].i != mesa.mesa[j].d){
				printf("%d:%d|", mesa.mesa[j].i, mesa.mesa[j].d);
			}
		        else if(m==2 && mesa.mesa[j].i != mesa.mesa[j].d){
				printf("    ");
			}
			else if(m==2 && mesa.mesa[j].i == mesa.mesa[j].d){
				printf("%d|", mesa.mesa[j].d);
			}
		}
		printf("\n");
	}
}


