#include "vetor_encadeado.h"

void imprimeLista(No_t* cabeca){
    No_t* noAtual = cabeca;
    while(noAtual != NULL){
        printf("%d [%d] \n", noAtual->valor, &noAtual->valor);
        noAtual = noAtual->proximo;
    }
    printf("\n");
}

No_t *criaNo(int valor){
    No_t *novoNo = malloc(sizeof(No_t));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

No_t *insereNoACabeca(No_t **cabeca, No_t *noAInserir){
    noAInserir->proximo = *cabeca;//Ponteiro para ponteiro
    *cabeca = noAInserir;
    return noAInserir;
}

//Funcao pouco confiavel...
void insereNoAoFinal(No_t **cabeca, No_t *noAInserir){
    No_t* noAtual = *cabeca;
    if(*cabeca == NULL){
        noAInserir->proximo = *cabeca;
        *cabeca = noAInserir;
        return;
    }
    while(noAtual->proximo != NULL){
        noAtual = noAtual->proximo;
    }
    noAtual->proximo = noAInserir;
}

void insereNoApos(No_t *noAnterior, No_t* noAInserir){
    noAInserir->proximo = noAnterior->proximo;
    noAnterior->proximo = noAInserir;
}

No_t *encontraNo(No_t *cabeca, int valor){
    No_t *temporaria = cabeca;

    while(temporaria != NULL){
        if(temporaria->valor == valor){
            return temporaria;
        }
        temporaria = temporaria->proximo;
    }
    return NULL;
}

int main(){

    int menu = 0;
    No_t *cabeca = NULL;
    No_t *temporario;

    while(menu != 4){
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Imprimir lista\n");
        printf("4 - Sair\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Digite o valor a ser inserido: ");
                int valor;
                scanf("%d", &valor);
                temporario = criaNo(valor);
                insereNoACabeca(&cabeca, temporario);
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                int valorApos;
                scanf("%d", &valorApos);
                temporario = criaNo(valorApos);
                insereNoAoFinal(&cabeca, temporario);
                break;
            case 3:
                imprimeLista(cabeca);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }

    return 0;
}
