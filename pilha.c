#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"

pilha * criaPilha(int tam){

	pilha * p = malloc(sizeof(pilha));
	p->topo = 0;
	p->tam = tam;
	p->valor = malloc(tam * sizeof(int));

	if(p->valor == NULL){
		return(NULL);
	}
	return(p);
}

void destroiPilha(pilha * p){
	free(p->valor);
	free(p);
}

void empilha(pilha * p, int n){

	if(p->topo == p->tam){
		p = aumentaPilha(p);
	}
	p->valor[p->topo] = n;
	p->topo++;
}

int desempilha(pilha * p){
	if(!pilhaVazia(p)){
		p->topo--;
		return(p->valor[p->topo]);
	}
}

int pilhaVazia(pilha * p){
	return(p->topo == 0);
}

int topoPilha(pilha * p){
	if(!pilhaVazia(p)){
		return(p->valor[p->topo - 1]);
	}
}

pilha * aumentaPilha(pilha * p){
	int tam_n = 2 * p->tam;
	int * nova = malloc(tam_n * sizeof(int));
	int i = 0;
	for(i; i < p->topo; i++){
		nova[i] = p->valor[i];
	}
	p->valor =  nova;
	p->tam = tam_n;
	return(p);
}

void imprimePilha(pilha * p){
	int i = 0;
	for(i; i < p->topo; i++){
		printf("%d ", p->valor[i]);
	}
	printf("\n");
}

