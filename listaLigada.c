#include<stdio.h>
#include<stdlib.h>
#include "listaLigada.h"

int vazia(celula * inicio){
	return(inicio == NULL);
}

void imprimeLista (celula * inicio) {
  if (!vazia(inicio)) {
    printf ("%d ", inicio->linha);
    imprimeLista (inicio->proximo);
  }
  else printf("\n"); 
}

celula * criaListaLigada(){
	celula * inicio = NULL;
	inicio = (celula*) malloc(sizeof(celula));
	inicio->proximo = NULL;
}

void insereFim(celula * inicio, int n){
	celula * aux = inicio;
	celula * nova = (celula*)malloc(sizeof(celula));
	while(aux->proximo != NULL){
		aux = aux->proximo;
	}
	aux->proximo = nova; 
	nova->linha = n;
	nova->proximo = NULL;
}

void insereInicio(celula ** inicio, int n){
	celula * nova = (celula*)malloc(sizeof(celula)); 
	nova->linha = n;
	nova->proximo = *inicio;
	*inicio = nova;
}

void inserePos(celula ** inicio, int pos, int n){
		if(pos == 0){
			insereInicio(inicio, n);
			return;
		}
		celula * aux = *inicio;
		celula * nova = (celula*)malloc(sizeof(celula));
		nova->linha = n;
		int i = 1;
		while(i != pos){
			aux = aux->proximo;
			i++;
			if(aux->proximo == NULL){
				break;
			}
		}

		nova->proximo = aux->proximo;
		aux->proximo = nova;		
}

int tamanhoLista(celula * inicio){
	if(vazia(inicio)){
		return(0);
	}
	int cont = 1 + tamanhoLista(inicio->proximo);
	return(cont);
}

celula * busca(celula * inicio, int n){
	if(vazia(inicio)|| inicio->linha == n){
		return(inicio);
	}
	return(busca(inicio->proximo, n));
}

celula * removeInicio(celula * inicio){
	celula * aux = inicio;
	if(!vazia(inicio)){
		inicio = inicio->proximo;
		free(aux);
	}
	return(inicio);
}

celula * removeFim(celula * inicio){
	celula * aux = inicio;

	if(inicio->proximo == NULL){
		free(aux);
		return(removeInicio(inicio));
	}
	
	while(aux->proximo->proximo != NULL){
		aux = aux->proximo;	
	}

	aux->proximo = NULL;
	return(inicio);
}

celula * removeCelula(celula * inicio, int n){
	celula * aux = inicio;
	if(vazia(inicio)){
		return(inicio);
	}
	if(inicio->linha == n){
		return(removeInicio(inicio));
	} else{
		inicio->proximo = removeCelula(inicio->proximo, n);
	}
	return(inicio);
}

void inverteLista(celula ** inicio){
	celula * ant = NULL;
	celula * atual = *inicio;
	celula * prox = NULL;
	while(!vazia(atual)){
		prox = atual->proximo;

		atual->proximo = ant;
		ant = atual;
		atual = prox;
	}
	*inicio = ant;
}

