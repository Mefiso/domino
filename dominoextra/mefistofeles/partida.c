#include <stdio.h>
#include "partida.h"
#include "colores.h"
#include "duerme.h"
#include "preguntas.h"
#include "azar.h"

void partida()
{ 
  tjugadores jugadores;
  
  tplayer tiradas;

  tpila pila;

  tmesa mesa;

  char ohm, dosde;
  
  int i, j, pasar=0, peso, min=666, win_block;
  inicializar_azar();
 
  do{
        
	printf("¿Numero de jugadores? [2-4]: ");
	scanf("%d%*c", &jugadores.nplayers); 
  
  }while( jugadores.nplayers != 2 && jugadores.nplayers != 3 && jugadores.nplayers != 4);
  
  do{
   printf("¿Un jugador humano? [s/n]: ");
   scanf("%c%*c", &jugadores.humano);  
   convertir_a_minusculas(&(jugadores.humano));
  }while( jugadores.humano != 's' && jugadores.humano != 'n');

  
  do{
     printf("¿Quieres omnisciencia? [s/n]: ");
     scanf("%c%*c", &ohm);
     convertir_a_minusculas(&ohm);
  }while( ohm != 's' && ohm != 'n');
  
  do{
     printf("¿Quieres ver la mesa en 2D? [s/n]: ");
     scanf("%c%*c", &dosde);
     convertir_a_minusculas(&dosde);

  }while( dosde != 's' && dosde != 'n');
  printf("\n");
  pila=inicializar_pila(pila, &jugadores);
  mesa=inicializar_mesa(mesa, &jugadores);
 
  do{
	  jugadores.turno= (jugadores.turno+1)% jugadores.nplayers;
	  mostrar_partida(jugadores, pila, mesa, ohm, dosde);
	  duerme_un_rato();
	  mostrar_tiradas_posibles(&mesa, &jugadores, ohm, &pila, &pasar);
  }while(jugadores.P[jugadores.turno].nfichas > 0 && pasar!=jugadores.nplayers);
  
  if (jugadores.P[jugadores.turno].nfichas ==0 && jugadores.turno ==0 && jugadores.humano== 's'){
	  printf_color(4);
	  printf("===>>> HAS GANADO ;-) <<<===\n");
	  printf_reset_color();
  }
  else if (jugadores.P[jugadores.turno].nfichas ==0){
	  printf_color(4);
	  printf("===>>> HA GANADO J%d ;-/ <<<===\n", jugadores.turno);
	  printf_reset_color();
  }
  else{
	  for(i=0; i<jugadores.nplayers; i++){
		peso=0;
		for(j=0; j<jugadores.P[i].nfichas; j++){
			peso=peso+ jugadores.P[i].player[j].i + jugadores.P[i].player[j].d;
		}
		if(peso<min){
			min=peso;
			win_block=i;
		}
	  }
	  printf_color(4);
	  printf("===>>> JUEGO BLOQUEADO. :-| <<<===\n");
	  if(jugadores.turno==0 && jugadores.humano== 's')
		printf("===>>> HAS GANADO ;-) <<<===\n");
	  else{
		printf("===>>> HA GANADO J%d ;-/ <<<===\n", win_block);
	  }
	  printf_reset_color();
  }
}
