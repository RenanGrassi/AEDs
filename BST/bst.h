#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct No * apontadorNo;

//Estrutura que contem o no
struct No{
    int Chave;
    apontadorNo filhoEsquerda;
    apontadorNo filhoDireita;
};

//Estrutura que gera um novo no em BST
apontadorNo geraNo(int valor);

//Percorrer em ordem
void emOrdem(struct No* raiz);
/*  Funcao para inserir um novo
    No com uma dada Chave na Arvore BST */
apontadorNo inserir(struct No* no, int chave);