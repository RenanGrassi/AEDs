#include "cartas.h"

extern const char* NomeValor[];
extern const char* NomeNaipe[];

const char* NomeValor[] = {
    "As", "Dois", "Tres", "Quatro", "Cinco", "Seis",
    "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"
};

const char* NomeNaipe[] = {
    "Ouros", "Espadas", "Copas", "Paus"
};

//Função para gerar um baralho completo
void geraBaralho(Lista* lista){
    Carta carta;
    for(int i = 0; i < 52; i++){
        carta = geraCartaAleatoria();
        inserirInicio(lista, carta);
    }
}

void geraBaralhoCompleto(Lista* lista){
    Carta carta;
    for(int i = 0; i < 52; i++){
        carta = geraCartaAleatoria();
        inserirInicio(lista, carta);
    }
}

//Função para gerar carta aleatória
Carta geraCartaAleatoria(){
    Carta carta;
    carta.valor  = (uint8_t)rand() % 13; //Valores de 0 a 12 (As a Rei)
    carta.naipe = (uint8_t)rand() % 4;  //Naipes de 0 a 3 (Ouros, Espadas, Copas, Paus)
    return carta;
}

// Função para alocar uma mão de 3 cartas do topo do baralho
Lista alocarMao(Lista* baralho){
    Lista mao;
    inicializarLista(&mao);

    for (int i = 0; i < 3; i++){
        if (baralho->cabeca != NULL){
            Carta carta = baralho->cabeca->carta;
            inserirInicio(&mao, carta);

            // Remover a carta do topo do baralho
            No* temp = baralho->cabeca;
            baralho->cabeca = baralho->cabeca->proximo;
            free(temp);
        }
    }
    return mao;
}
//Função para criar um novo nó com a carta informada
No* criarNo(Carta carta){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->carta = carta;
    novoNo->proximo = NULL;
    return novoNo;
}

//Função para inicializar a lista encadeada
void inicializarLista(Lista* lista) {
    lista->cabeca = NULL;
    lista->cauda = NULL;
}

//Função para verificar se uma carta já existe na lista
int cartaJaExiste(Lista lista, Carta carta){
    No* atual = lista.cabeca;
    while (atual != NULL) {
        if (atual->carta.valor == carta.valor && atual->carta.naipe == carta.naipe) {
            return 1; // A carta já existe na lista
        }
        atual = atual->proximo;
    }
    return 0; //A carta não existe na lista
}

//Função para inserir um novo nó (carta) no início da lista, desde que ela não exista ainda
void inserirInicio(Lista* lista, Carta carta) {
    if (!cartaJaExiste(*lista, carta)) {
        No* novoNo = criarNo(carta);

        if (lista->cabeca == NULL) {
            lista->cabeca = novoNo;
            lista->cauda = novoNo;
        }else{
            novoNo->proximo = lista->cabeca;
            lista->cabeca = novoNo;
        }
    }else{
        printf("A carta com valor %d e naipe %d já existe no baralho.\n", carta.valor, carta.naipe);
    }
}

//Função para exibir a lista encadeada
void exibirLista(Lista lista){
    No* atual = lista.cabeca;
    while (atual != NULL) {
        /*printf("Valor: %d, Naipe: %d\n", atual->carta.valor, atual->carta.naipe);
        atual = atual->proximo;*/
        printf("Valor: %s, Naipe: %s\n", NomeValor[atual->carta.valor], NomeNaipe[atual->carta.naipe]);
        atual = atual->proximo;
    }
}

//Função para liberar a memória ocupada pela lista encadeada
void liberarLista(Lista* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
    lista->cauda = NULL;
}

int main(){
    Lista lista;
    int16_t menu = 0;

    while (menu != 2){
        printf(":::::::CARTAS:::::::\n");
        printf("1 - Gerar Baralho:\n");
        printf("2 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%hd", &menu);

        switch (menu){
            case 1:
                inicializarLista(&lista);
                geraBaralhoCompleto(&lista);
                exibirLista(lista);
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }
    return 0;
}
/*
    // Exemplo: Inserir algumas cartas no início da lista
    Carta carta1 = {As, Ouros};
    Carta carta2 = {Rei, Copas};
    Carta carta3 = {Sete, Espadas};
*/
