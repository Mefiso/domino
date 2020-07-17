#include "partida.h"

tmesa inicializar_mesa(tmesa mesa, tjugadores *jugadores){
	  int maxi, maxj, i, j;
	  mesa.mesa[0].i=0;
	  mesa.mesa[0].d=0;
	  for(i=0; i<jugadores->nplayers; i++)
	  {
	  	for(j=0; j<7; j++) 
	    {
	         if(jugadores->P[i].player[j].i == jugadores->P[i].player[j].d)
	         { 
	            if(mesa.mesa[0].i < jugadores->P[i].player[j].i)
	            {
	                mesa.mesa[0].i =jugadores->P[i].player[j].i;
	                mesa.mesa[0].d = jugadores->P[i].player[j].d;
	                maxi=i;
	                maxj=j;
	                jugadores->turno= i;             
	            }               
	         }
	     }
	   }
	  mesa.num=1;
	  for (i=maxj; i<7; i++){
		  (*jugadores).P[maxi].player[i].i=(*jugadores).P[maxi].player[i+1].i;
		  (*jugadores).P[maxi].player[i].d=(*jugadores).P[maxi].player[i+1].d;
	  }
	  (*jugadores).P[maxi].nfichas --;
	  return(mesa);
}