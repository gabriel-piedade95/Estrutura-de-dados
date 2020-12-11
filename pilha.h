#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int tam;
	int topo;
	int * valor;
}pilha;

pilha * criaPilha(int tam);
void destroiPilha(pilha * p);
void empilha(pilha * p, int n);
int desempilha(pilha * p);
int pilhaVazia(pilha * p);
int topoPilha(pilha * p);
pilha * aumentaPilha(pilha * p);
void imprimePilha(pilha * p);

