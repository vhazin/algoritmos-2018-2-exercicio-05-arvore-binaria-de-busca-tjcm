#include <stdio.h>
#include <stdlib.h>

typedef struct no_arvore{  // estrutura básica do nó
	int valor;
	struct no_arvore *esq;
	struct no_arvore *dir;
	struct no_arvore *pai;
}No 

No *criararvore(int info, No *esquerda, No *direita){  // função para criar o nó raiz da arvore
	No *raiz = malloc(sizeof(No));
	raiz->valor = info;
	raiz->esq = esquerda;
	raiz->dir = direita;
	raiz->esq->pai = raiz;
	raiz->dir->pai = raiz;
	return raiz;
}

No *inserir (int info, No *arvore){  // inserir um novo nó na arvore
	if(arvore == NULL){
		arvore = criararvore(info, NULL, NULL);
	} else if( info < arvore->valor){
		arvore->esq = inserir(info, arvore->esq);
		arvore->esq->pai = arvore;
	} else{
		arvore->dir = inserir(info, arvore->dir);
		arvore->dir-> = arvore;
	}
}

void preordem (No raiz){
	if (raiz != NULL){
		printf(" %d", raiz->valor );
		preordem(raiz->esq);
		preordem(raiz->dir);
	}
}




int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}