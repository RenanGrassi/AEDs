#include "bst.h"

void Inicializa(Apontador *no){
    no = NULL;   
}

int Insere(Apontador *p, int Reg){
    if(*p == NULL){
        *p = (Apontador)malloc(sizeof(No));
        (*p)->Reg = Reg;
        (*p)->Esq = NULL;
        (*p)->Dir = NULL;
        return 1;
    }
    if(Reg < (*p)->Reg){
        return Insere(&(*p)->Esq,Reg);
    }else if(Reg > (*p)->Reg){
        return Insere(&(*p)->Dir,Reg);
    }else{
        printf("Erro: O Registro ja consta na arvore!\n");
        return 0;
    }
}

int Pesquisa(Apontador *p, int Reg){
    if(*p == NULL){
        printf("Erro: O Registro nao consta na arvore!\n");
        return 0;
    }else if(Reg < (*p)->Reg){
        return Pesquisa(&(*p)->Esq, Reg);
    }else if(Reg > (*p)->Reg){
        return Pesquisa(&(*p)->Dir, Reg);
    }else{
        printf("Registro encontrado!\n");
        return 1;
    }
}

int Retira(Apontador *p, int Reg){
    Apontador aux;
    if(*p == NULL){
        printf("Erro: O Registro nao consta na arvore!\n");
        return 0;
    } else if(Reg < (*p)->Reg){
        return Retira(&(*p)->Esq, Reg);
    } else if(Reg > (*p)->Reg){
        return Retira(&(*p)->Dir, Reg);
    }

    if((*p)->Dir == NULL){
        aux = *p; *p = (*p)->Esq;
        free(aux);
        return 1;
    }

    if((*p)->Esq != NULL){
        Antecessor(*p, &(*p)->Esq);
        return 1;
    }

    aux = *p; *p = (*p)->Dir;
    free(aux);
    return 1;
}

void Antecessor(Apontador p, Apontador *r){
    Apontador aux;
    if((*r)->Dir != NULL){
        Antecessor(p, &(*r)->Dir);
        return;
    }
    p->Reg = (*r)->Reg;
    aux = *r;
    *r = (*r)->Esq;
    free(aux);
}

void Ordem(Apontador *p){
    if(*p){
        Ordem(&(*p)->Esq);
        printf("%d ", (*p)->Reg);
        Ordem(&(*p)->Dir);
    }
}

void PreOrdem(Apontador *p){
    if(*p){
        printf("%d ", (*p)->Reg);
        Ordem(&(*p)->Esq);
        Ordem(&(*p)->Dir);
    }
}

void PosOrdem(Apontador *p){
    if(*p){
        Ordem(&(*p)->Esq);
        Ordem(&(*p)->Dir);
        printf("%d ", (*p)->Reg);
    }
}

int Altura(Apontador p){
    if(p == NULL){
        return -1;
    }else{
        int he = Altura(p->Esq);
        int hd = Altura(p->Dir);
        if(he < hd){
            return hd + 1;
        }else{
            return he + 1;
        }
    } 
}

int main(){
    
    int menu = 0, x;

    Apontador arvore = NULL;
    Inicializa(&arvore);

    while(menu > -1 && menu < 8){
        printf(":::Arvore BST(ja inicializada):::\n");
        printf("1 - Para inserir na Arvore\n");
        printf("2 - Para retirar na Arvore\n");
        printf("3 - Para percorrer a Arvore em Ordem\n");
        printf("4 - Para percorrer a Arvore em Pos Ordem\n");
        printf("5 - Para percorrer a Arvore em Pre Ordem\n");
        printf("6 - Para saber a altura da Arvore.\n");
        printf("7 - Sair\n");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("Digite o numero para ser inserido: ");
                scanf("%d", &x);
                Insere(&arvore, x);
                printf("\nInserido com Sucesso!\n");
            break;
            case 2:
                printf("Digite o numero para ser retirado: ");
                scanf("%d", &x);
                Retira(&arvore, x);
                printf("\nRetirado com Sucesso!\n");
            break;
            case 3:
                Ordem(&arvore);
                printf("\n");
            break;
            case 4:
                PosOrdem(&arvore);
                printf("\n");
            break;
            case 5:
                PreOrdem(&arvore);
                printf("\n");
            break;
            case 6:
                printf("Altura da arvore: %d ", Altura(arvore));
                printf("\n");
            break;
            case 7:
                break;
            break;
            default:
                printf("Opcao invalida!\n");
            break;
        }
    }

    return 0;
}
