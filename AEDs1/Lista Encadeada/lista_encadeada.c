//Autor: Renan Grassi auxiliado pelo Gui
// :^)
//Data: 16/01/2023
#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct  No* proximo;
}No;
typedef struct No No_t;

void imprimeLista(No_t* cabeca);
No_t *criaNo(int valor);
No_t *insereNoACabeca(No_t **cabeca, No_t *noAInserir);
No_t *encontraNo(No_t *cabeca, int valor);
void insereNoApos(No_t *noAnterior, No_t *noAInserir);
