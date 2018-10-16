#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoItem tipoitem;

struct TipoItem{
    char nome_doc[50];
    tipoitem *proximo;
};

typedef struct fila Fila;

struct fila{
    tipoitem *inicio;
    tipoitem *fim;
    int tamanho;
};

Fila *criaFila(){
    Fila *fila=(Fila *) malloc(sizeof(Fila));
    fila->tamanho=0;
    fila->inicio=NULL;
    fila->fim=NULL;
    return fila;
}


void enfileira(Fila *fila, char *nome_doc){
    fila->tamanho++;
    tipoitem *novo = (tipoitem *) malloc(sizeof(tipoitem));
    strcpy(novo->nome_doc,nome_doc);
    novo->proximo=NULL;
    if(fila->inicio == NULL){
        fila->inicio=novo;
        fila->fim=fila->inicio;
    }else{
        fila->fim->proximo=novo;
        fila->fim=fila->fim->proximo;
    }
}


void desenfileirar(Fila *fila){
    if(fila->tamanho==0){
        printf("\nFila vazia.");
    }    else if(fila->fim == fila->inicio){
        fila->tamanho--;
        free(fila->inicio);
        printf("\nO documento foi impresso.");

    }else{
        fila->tamanho--;
        tipoitem *aux = fila->inicio;
        fila->inicio = fila->inicio->proximo;
        free(aux);
        printf("\nO documento foi impresso.");
    }
}

void printar (Fila *fila){
    tipoitem *indice = fila->inicio;
    int i = 0;
    while(i<fila->tamanho){
        printf("%s\n",indice->nome_doc);
        indice=indice->proximo;
        i++;
    }
}






int valor_entrada;

int main()
{

    Fila *fila = criaFila();
    while(1){
        printf("\n-----------------------------------------");
        printf("\n----------IMPRESSORA JATEX---------------");
        printf("\n-----------------------------------------");

        printf("\n\n---------------MENU----------------------");
        printf("\n\n1) PRA CRIAR UM DOCUMENTO");
        printf("\n2) PARA  MOSTRAR TODOS OS DOCUMENTOS");
        printf("\n3) PARA IMPRIMIR O DOCUMENTO");
        printf("\n4) MANUAL DE INSTRUCOES");
        printf("\n5) SAIR");

        //captura o valor da entrada
        printf("\n\nEscolha uma opcao:");
        scanf("\n%d",&valor_entrada);

        if(valor_entrada==1){

            char nome_do_documento[50];
            printf("\nDigite o nome do documento:");
            scanf("%s",&nome_do_documento);
            enfileira(fila,nome_do_documento);
            printf("Documento criado!\n\n");

        }else if(valor_entrada==2){

            printf("\n\n*************** TODOS OS DOCUMENTOS ***************\n");
            if(fila->tamanho==0){
                printf("\nNenhum documento na fila de impressao.\n");
            }else{
                printf("\n");
                 printar(fila);
            }

        }else if(valor_entrada==3){
             desenfileirar(fila);
        }else if(valor_entrada==4){
            printf("\n\n*************** MANUAL DE INSTRUCOES ***************");
            printf("\nManual de instrucoes da simuladora de impressora jatex.\n Este programa simula o funcionamento de uma impressora.\n");
            printf("\nOpc 1: Eh possivel simular a criacao de um documento.\n");
            printf("\nOpc 2: Mostra todos os documentos que estao enfileirados.\n");
            printf("\nOpc 3: Como o programa simula as filas da impressora e as filas utilizam \no principio FIFO, o primeiro documento da fila eh impresso.\n");
            printf("\nOpc 4: Manual de instrucoes.\n");
            printf("\nOpc 5: Clique 5 para sair e finalizar o funcionamento da impressora.");
            printf("\n******************************************************");

        }else if(valor_entrada==5){
            printf("Programa finalizado.");
            break;
        }


    }
    return 0;
}
