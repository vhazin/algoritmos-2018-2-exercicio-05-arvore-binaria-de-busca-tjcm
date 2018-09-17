//
//  main.c
//  arvorebinaria
//
//  Created by Thiago Moraes on 13/09/2018.
//  Copyright © 2018 Thiago Moraes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct no{  // estrutura básica do nó
    int valor;
    struct no *esq;
    struct no *dir;
    struct no *pai;
}No;

struct no *criararvore(int info, No *esquerda, No *direita){
    No *raiz=malloc(sizeof(No));
    raiz->valor = info;
    raiz->esq = esquerda;
    raiz->dir = direita;
    //raiz->esq->pai = raiz;
    //raiz->dir->pai = raiz;
    return raiz;
}

struct no *inserir (int info, No *arvore){  // inserir um novo nó na arvore
    if(arvore == NULL){
        arvore = criararvore(info, NULL, NULL);
    }else if(info<arvore->valor){
        arvore->esq = inserir(info, arvore->esq);
       // arvore->esq->pai = arvore;
    } else{
        arvore->dir = inserir(info, arvore->dir);
        //arvore->dir->pai = arvore;
    }
    return arvore;
}

void preordem (struct no *raiz){
    if (raiz != NULL){
        printf(" %d", raiz->valor );
        preordem(raiz->esq);
        preordem(raiz->dir);
    }
    return;
}

void inordem (struct no *raiz){
    if (raiz != NULL){
        inordem(raiz->esq);
        printf(" %d", raiz->valor);
        inordem(raiz->dir);
    }
    return;
}

void posordem (struct no *raiz){
    if (raiz != NULL){
        posordem(raiz->esq);
        posordem(raiz->dir);
        printf(" %d", raiz->valor);
    }
    return;
}

int main(){
    int testes, numeros;
    int i, j, t;
    
    
    scanf("%d",&testes);
    No *arvores[testes];
    for (i = 0; i < testes; i++){
        scanf("%d",&numeros);
        for (j = 0; j < numeros; j++){
            scanf("%d",&t);
            if (j==0) {
                arvores[i] = criararvore(t, NULL, NULL);
                continue;
            }
            arvores[i] = inserir(t,arvores[i]);
        }
    }
    
    for (i = 0; i < testes; i++){
        printf("Case %d:",(i+1));
        printf("\nPre.:");
        preordem(arvores[i]);
        printf("\nIn..:");
        inordem(arvores[i]);
        printf("\nPost:");
        posordem(arvores[i]);
        printf("\n\n");
    }
    
    return 0;
}
