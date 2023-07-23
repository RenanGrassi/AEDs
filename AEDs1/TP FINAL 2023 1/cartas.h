#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

//Enums para os naipes e valores das cartas
enum Naipes{
    Ouros, 
    Espadas, 
    Copas, 
    Paus
}Naipe;
enum Valores{
    As, Dois, Tres, 
    Quatro, Cinco, Seis, 
    Sete, Oito, Nove, Dez,
    Valete, Dama, Rei
}Valor;

//Estrutura da Carta
typedef struct Carta{
    uint8_t valor;
    uint8_t naipe;
}Carta;

//Definição do nó da lista encadeada
typedef struct No{
    Carta carta;
    struct No* proximo;
}No;

//Definição da lista encadeada
typedef struct Lista{
    No* cabeca;
    No* cauda; //Opcional: otimiza a inserção no final da lista
}Lista;

No* criarNo(Carta carta);
void inicializarLista(Lista* lista);
int cartaJaExiste(Lista lista, Carta carta);
void inserirInicio(Lista* lista, Carta carta);
void exibirLista(Lista lista);
void liberarLista(Lista* lista);
Carta geraCartaAleatoria();
void inserirInicio(Lista* lista, Carta carta);
Lista alocarMao(Lista* baralho);
