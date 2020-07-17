#include "azar.h"
#include "partida.h"
#define MEFISTOFELES 666
tpila inicializar_pila(tpila pila, tjugadores *jugadores)
{
	int i, j, k=0, m=0;
	tficha aux;
	for (i=0; i<7; i++){
		for(j=m; j<7; j++){
			pila.pila[k].i= i;
			pila.pila[k].d= j;
			k++;
		}
		m++;
	} /*m=control, k=posicion en el struct*/
	for (i=0; i<MEFISTOFELES; i++){
		j= numero_al_azar(28);
		do{
			k=numero_al_azar(28);
		}while(k==j);
		aux= pila.pila[k];
		pila.pila[k]=pila.pila[j];
		pila.pila[j]=aux;
	}
	pila.npila=28;
	for(i=0; i<(*jugadores).nplayers; i++){
		(*jugadores).P[i].nfichas = 0;
		for(j=0; j<7; j++){
			(*jugadores).P[i].player[j]= pila.pila[pila.npila-1];
			pila.pila[pila.npila-1].i = -1;
			pila.pila[pila.npila-1].d = -1;
			pila.npila--;
			(*jugadores).P[i].nfichas ++;
		}
	}
return (pila);
}	
