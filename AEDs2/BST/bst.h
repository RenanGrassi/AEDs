#include<stdlib.h>
#include<stdio.h>

typedef struct No * Apontador;
typedef struct No{
    int Reg;
    Apontador Esq, Dir;
}No;

void Inicializa(Apontador *no);
int Insere(Apontador *p, int Reg);
int Pesquisa(Apontador *p, int Reg);
void Ordem(Apontador *p);
void PosOrdem(Apontador *p);
void PreOrdem(Apontador *p);
int Altura(Apontador p);
void Antecessor(Apontador p, Apontador *r);
int Retira(Apontador *p, int Reg);
