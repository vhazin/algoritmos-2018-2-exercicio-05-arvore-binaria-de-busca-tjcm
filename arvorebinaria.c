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



int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}