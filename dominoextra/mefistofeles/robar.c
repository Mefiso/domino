#include "partida.h"
#include <stdio.h>
#include "colores.h"
void robar(tpila *pila, tjugadores *jugadores,char ohm, int *paso){
  if((*pila).npila !=0){
	int x= (*jugadores).turno, y= (*jugadores).P[x].nfichas;	
	(*jugadores).P[x].player[y].i= (*pila).pila[(*pila).npila-1].i;
	(*jugadores).P[x].player[y].d= (*pila).pila[(*pila).npila-1].d;
	(*jugadores).P[x].nfichas++;
	(*pila).pila[(*pila).npila-1].i= -1;
	(*pila).pila[(*pila).npila-1].d= -1;
	(*pila).npila --;
	if((*jugadores).turno == 0)
		printf("\nVas a la pila! Pillas un %d:%d| ;-P", (*jugadores).P[x].player[y].i, (*jugadores).P[x].player[y].d );
	else if(ohm=='s' && (*jugadores).turno != 0){
		printf("\nVa a la pila! Pilla un %d:%d| ;-P", (*jugadores).P[x].player[y].i, (*jugadores).P[x].player[y].d );
	}
	else{
		printf("\nVa a la pila! ;-P");
	}
  }
  else if((*jugadores).turno == 0 && (*jugadores).humano=='s'){
	  printf_color(2);
	  printf("\nPasas! :-(");
	  *paso = 1;
	  printf_reset_color();
  }
  else{
	  printf_color(2);
	  printf("\nPasa! :-)");
	  *paso = 1;
	  printf_reset_color();
  }
}
