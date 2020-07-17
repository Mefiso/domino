#include <stdio.h>
#include "partida.h"
#include "duerme.h"
#include "colores.h"

void mostrar_partida(tjugadores jugadores, tpila pila, tmesa mesa, char ohm, char dosde)
{
	int j, x;
	printf("Pila:    ");
	if(ohm=='s'){
		for(j=0; j<pila.npila; j++){
				printf("%d:%d|", pila.pila[j].i, pila.pila[j].d);
			}
	}
	else{
		for(j=0; j<pila.npila; j++){
						printf("?:?|");
					}
	}
	duerme_un_nano_rato();
	printf_color(0);
	printf("\nMesa:    ");
   if(dosde=='s'){
	mostrar_mesa_dosde(mesa);
   }
   else{
	for(j=0; j<mesa.num; j++)
	{
		printf("%d:%d|", mesa.mesa[j].i, mesa.mesa[j].d);
	}
	printf("\n");
	
  }
	duerme_un_nano_rato();
	if(ohm=='s'){
		for(j=0; j<jugadores.nplayers; j++){
                                printf_color(1);
				printf("J%d:      ", j);
				for(x=0; x<jugadores.P[j].nfichas; x++){
					printf("%d:%d|", jugadores.P[j].player[x].i, jugadores.P[j].player[x].d);
				}
				if(jugadores.humano=='s' && j==0){
                                        
					printf("Humano\n");
				}
				else{
					printf("Robot\n");
				}
			}
	}
	else{
		for(j=0; j<jugadores.nplayers; j++){
				printf_color(1);
				printf("J%d:      ", j);
        
				if(jugadores.humano=='s' && j==0){
					for(x=0; x<jugadores.P[j].nfichas; x++){
                                              
						printf("%d:%d|", jugadores.P[j].player[x].i, jugadores.P[j].player[x].d);
                                                
					}
                                        
					printf("Humano\n");
                                        
				}
				else{
					for(x=0; x<jugadores.P[j].nfichas; x++){
                                                
						printf("?:?|");
                                                
					}
                                        
					printf("Robot\n");
                                        
				}
			}

	}
		duerme_un_nano_rato();
                printf_color(4);
		printf("Turno: %d", jugadores.turno);
                printf_reset_color();
}
