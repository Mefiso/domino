#include "partida.h"
#include <stdio.h>
#include "colores.h"

void mostrar_tiradas_posibles(tmesa *mesa, tjugadores *jugadores, char ohm, tpila *pila, int *pasar)
{
  int i=jugadores->turno, j, aux= 0, positions[15], paso, cont=0, pos1=0, pos2=0 ;
  char tiradas_posibles[15];
 
 
  do{
	  	paso=0;
		printf_color(2);
     for (j=0; j<(*jugadores).P[i].nfichas; j++)
     {
       if ((*jugadores).P[i].player[j].d == (*mesa).mesa[mesa->num-1].d  || (*jugadores).P[i].player[j].i== (*mesa).mesa[mesa->num-1].d)
       {
        tiradas_posibles[aux] = 'd';
        positions[aux]=j;
        aux++;
       }
       if ((*jugadores).P[i].player[j].i== (*mesa).mesa[0].i || (*jugadores).P[i].player[j].d== (*mesa).mesa[0].i)
       {
    	   tiradas_posibles[aux] = 'i';
    	   positions[aux]=j;
           aux++;
       }
     }
     
     if(aux==0)
    	 robar(&(*pila), &(*jugadores), ohm, &paso);
   }while(aux==0 && paso !=1);

if(ohm== 's' || (ohm=='n' && (*jugadores).turno== 0 && jugadores->humano == 's'))
{
  printf("\nTiradas posibles: ");

   for(j=0; j<aux; j++){

      if((*jugadores).P[i].player[positions[j]].i == (*jugadores).P[i].player[positions[j]].d){
         
         cont++;
         if(cont ==1)
           { 
               pos1=j;
           }
         if(cont ==2)
           {
               pos2=j;
           }
      }
   }

if(cont==2)
     {
if(tiradas_posibles[pos1] != tiradas_posibles[pos2])
{
     
      for(j=aux-1; j>=0; j--)
       {
     
        positions[j+1]=  positions[j];
        tiradas_posibles[j+1] = tiradas_posibles[j];
       
       }
       positions[0]=-1;
      aux++;

       printf("0(i%d:%d|%d:%d|) ", (*jugadores).P[i].player[pos1].i, (*jugadores).P[i].player[pos1].d, (*jugadores).P[i].player[pos2].i, (*jugadores).P[i].player[pos2].d);

  }

}
for(j=0; j<aux; j++){

if(positions[0]!= -1)
{
printf ("%d(%c%d:%d|) ", j, tiradas_posibles[j], (*jugadores).P[i].player[positions[j]].i, (*jugadores).P[i].player[positions[j]].d); 
}

}
}




  	  printf_reset_color();
  	  printf("\n");
  	  if(paso==0){
  		tirar_ficha(&(*mesa), &(*jugadores), tiradas_posibles, positions, aux, pos1, pos2);
                *pasar=0;
  	  }
  	  else{
  		  *pasar = *pasar +1;
  	  }
  	  printf("\n");
}
    




	
