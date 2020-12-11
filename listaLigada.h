#include<stdio.h>
#include<stdlib.h>

typedef struct cel{
	int valor;
	struct cel * proximo;
} celula;

int vazia(celula * inicio);
void imprimeLista (celula * inicio);
celula * criaListaLigada();
void insereFim(celula * inicio, int n);
void insereInicio(celula ** inicio, int n);
void inserePos(celula ** inicio, int pos, int n);
celula * removeInicio(celula * inicio);
celula * removeFim(celula * inicio);
celula * removeCelula(celula * inicio, int n);
int tamanhoLista(celula * inicio);
celula * busca(celula * inicio, int n);
void inserePos(celula ** inicio, int pos, int n);
void inverteLista(celula ** inicio);
celula * inverte(celula * inicio);
