#include<stdio.h>
#include<stdlib.h>

//Estrutura que contem o no
struct No{
    int Chave;
    struct No *filhoEsquerda;
    struct No *filhoDireita;
};

//Estrutura que gera um novo no em BST
struct No* geraNo(int valor);

//Percorrer em ordem
void emOrdem(struct No* raiz);
/*  Funcao para inserir um novo
    No com uma dada Chave na Arvore BST */
struct No* inserir(struct No* no, int chave);