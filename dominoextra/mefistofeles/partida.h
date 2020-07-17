#ifndef PARTIDA_H
#define PARTIDA_H

typedef struct                              
{
	int d;
	int i;
	char lado;
	
}tficha;


typedef struct

{
	int num;
	tficha mesa[27];

}tmesa;


typedef struct

{
	
	int npila;
	
	tficha pila[28];

}tpila;


typedef struct

{

	int nfichas;

	tficha player[7];


}tplayer;


typedef struct

{
	
	int nplayers;

	char humano;

	int turno;

	tplayer P[4];

}tjugadores;

void partida();
tpila inicializar_pila(tpila pila, tjugadores *jugadores);
void mostrar_partida(tjugadores jugadores, tpila pila, tmesa mesa, char ohm, char dosde);
void mostrar_tiradas_posibles(tmesa *mesa, tjugadores *jugadores, char ohm, tpila *pila, int *pasar);
tmesa inicializar_mesa(tmesa mesa, tjugadores *jugadores);
void tirar_ficha(tmesa *mesa, tjugadores *jugadores, char tiradas[7], int positions[7], int numero, int pos1, int pos2);
void robar(tpila *pila, tjugadores *jugadores,char ohm, int *paso);
void mostrar_mesa_dosde(tmesa mesa);
int heuristica(tmesa *mesa, tjugadores *jugadores, char tiradas[15], int positions[15], int numero);

#endif

