//      Autor: Renan Grassi de Freitas Procopio
//      :^)
//      Fonte: geeksforgeeks.com, codigo revisado!

#include "bst.h"

apontadorNo geraNo(int valor){
    apontadorNo temp = (apontadorNo) malloc(sizeof(struct No));
    temp->Chave = valor;
    temp->filhoEsquerda = temp->filhoDireita = NULL;
    return temp;
}

//Percorrer em ordem
void emOrdem(struct No* raiz){
    if(raiz != NULL){
        emOrdem(raiz->filhoEsquerda);
        printf("%d \n", raiz->Chave);
        emOrdem(raiz->filhoDireita);
    }
}

struct No* inserir(struct No* no, int chave){
    //Se a Arvore esta vazia
    if(no == NULL){
        return geraNo(chave);
    }
    //Caso a Arvore ja exista, percorra ela
    if(chave < no->Chave){
        no->filhoEsquerda = inserir(no->filhoEsquerda, chave);
    }
    else if(chave > no->Chave){
        no->filhoDireita = inserir(no->filhoDireita, chave);
    }
    /* Retorna o ponteiro (nao alterado) para o No*/
    return no;
}

//Funcao Main

/*int main(){

    int menu = 0;

    while(){
        printf("         :::Arvore BST:::        \n");
        printf("1 - Inicializar\Inserir na Arvore\n");
        printf("2 - Percorrer Arvore em Ordem    \n");
        printf("3 - Sair                         \n");

        scanf("%d", &menu);

        switch(menu){
            case 1:
                int valor;
                struct No* raiz = NULL;
                printf("Digite o valor a ser inserido:\n");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:

                break;
            case 3:
                break;
            default:
            printf("Opcao invalida...\n");
        }
    }

    return 0;
}*/

int main(){
    apontadorNo raiz = NULL;
    raiz = inserir(raiz, 50);
    inserir(raiz, 35);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    //Percorre transversalmente a Arvore em Ordem printando os valores.
    emOrdem(raiz);

    return 0;
}

/* Exemplo de BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */