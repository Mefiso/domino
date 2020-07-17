#include "partida.h"
#include <stdio.h>

int heuristica(tmesa *mesa, tjugadores *jugadores, char tiradas[15], int positions[15], int numero){

int j,x, mefiso, max=0, turn=(*jugadores).turno, pos, aux;

for(j=0; j<numero; j++){
mefiso=0;
aux=j;
if(tiradas[j] == 'd'){
   
   for(x=0; x<mesa->num; x++)
   {
     if((mesa->mesa[x].i == mesa->mesa[0].i) || (mesa->mesa[x].d == mesa->mesa[0].i)){
       mefiso++;
      }
     if((*jugadores).P[turn].player[positions[aux]].d == (*mesa).mesa[(*mesa).num-1].d){
    	 if(mesa->mesa[x].i == (*jugadores).P[turn].player[positions[aux]].i || (mesa->mesa[x].d == (*jugadores).P[turn].player[positions[aux]].i )){
    		 mefiso++;
    	 }
     }
     else if((*jugadores).P[turn].player[positions[aux]].i == (*mesa).mesa[(*mesa).num-1].d){
    	 if(mesa->mesa[x].i == (*jugadores).P[turn].player[positions[aux]].d || (mesa->mesa[x].d == (*jugadores).P[turn].player[positions[aux]].d )){
    	    		 mefiso++;
    	    	 }
     }
   }
   for(x=0; x<jugadores->P[turn].nfichas; x++){
    
     if((jugadores->P[turn].player[x].i == mesa->mesa[0].i) || (jugadores->P[turn].player[x].d == mesa->mesa[0].i)){
    	 mefiso++;
     }
     if((*jugadores).P[turn].player[positions[aux]].d == (*mesa).mesa[(*mesa).num-1].d){
        	 if(jugadores->P[turn].player[x].i == (*jugadores).P[turn].player[positions[aux]].i || (jugadores->P[turn].player[x].d == (*jugadores).P[turn].player[positions[aux]].i )){
        		 mefiso++;
        	 }
     }
     else if((*jugadores).P[turn].player[positions[aux]].i == (*mesa).mesa[(*mesa).num-1].d){
             if(jugadores->P[turn].player[x].i == (*jugadores).P[turn].player[positions[aux]].d || (jugadores->P[turn].player[x].d == (*jugadores).P[turn].player[positions[aux]].d )){
        	     mefiso++;
        	 }
     }
   }
}
else if(tiradas[j] == 'i'){
	   for(x=0; x<mesa->num; x++)
	   {
	     if((mesa->mesa[x].i == mesa->mesa[mesa->num -1].d) || (mesa->mesa[x].d == mesa->mesa[mesa->num -1].d)){
	       mefiso++;
	      }
	     if((*jugadores).P[turn].player[positions[aux]].d == (*mesa).mesa[0].i){
	    	 if(mesa->mesa[x].i == (*jugadores).P[turn].player[positions[aux]].i || (mesa->mesa[x].d == (*jugadores).P[turn].player[positions[aux]].i )){
	    		 mefiso++;
	    	 }
	     }
	     else if((*jugadores).P[turn].player[positions[aux]].i == (*mesa).mesa[0].i){
	    	 if(mesa->mesa[x].i == (*jugadores).P[turn].player[positions[aux]].d || (mesa->mesa[x].d == (*jugadores).P[turn].player[positions[aux]].d )){
	    	    		 mefiso++;
	    	    	 }
	     }
	   }
	   for(x=0; x<jugadores->P[turn].nfichas; x++){
	    
	     if((jugadores->P[turn].player[x].i == mesa->mesa[mesa->num -1].d) || (jugadores->P[turn].player[x].d == mesa->mesa[mesa->num -1].d)){
	    	 mefiso++;
	     }
	     if((*jugadores).P[turn].player[positions[aux]].d == (*mesa).mesa[0].i){
	        	 if(jugadores->P[turn].player[x].i == (*jugadores).P[turn].player[positions[aux]].i || (jugadores->P[turn].player[x].d == (*jugadores).P[turn].player[positions[aux]].i )){
	        		 mefiso++;
	        	 }
	     }
	     else if((*jugadores).P[turn].player[positions[aux]].i == (*mesa).mesa[0].i){
	             if(jugadores->P[turn].player[x].i == (*jugadores).P[turn].player[positions[aux]].d || (jugadores->P[turn].player[x].d == (*jugadores).P[turn].player[positions[aux]].d )){
	        	     mefiso++;
	        	 }
	     }
	   }	
}
if((*jugadores).P[turn].player[positions[aux]].d == (*jugadores).P[turn].player[positions[aux]].i){
	mefiso = mefiso + 10;
}
printf_color(2);
printf("h(%d)= %d ", j, mefiso);
printf_reset_color();
if(max< mefiso){
	max=mefiso;
	pos=j;
}
}
printf("\n");
return(pos);
}

