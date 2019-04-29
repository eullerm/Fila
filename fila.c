#include "fila.h"
#include <stdio.h>

TFila *inicializa(void){
    TFila *f = (TFila *)malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int fila_vazia(TFila *f){
    if (f->inicio == NULL) {
        return 1;
    }
    else return 0;
}

void insere(TFila *f, int elem){
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = NULL; //inserção no fim da fila
    if (!fila_vazia(f)){
        f->fim->prox = novo;
    }
    else{
        f->inicio = novo;
    }
    f->fim = novo; //elemento inserido é o novo fim da fila
}

/*
 * Remove elemento da fila e retorna info do elemento excluído
 */
int retira(TFila *f){
    if (fila_vazia(f)){
        exit(1);
    }
    int info = f->inicio->info;

    TLista *aux = f->inicio;
    f->inicio=f->inicio->prox;
    //se elemento removido era o único da fila
    //faz fim apontar para NULL também
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(aux);
    return info;
}

void libera(TFila *f){
    TLista *q, *p = f->inicio;
    while(p != NULL){
        q = p;
        p = p->prox;
        free(q);
    }
    free(f);
}

void imprime_fila(TFila *f){
    //Checa e a fila está vazia.
    if(fila_vazia(f)) exit(1);

    else{
        TFila *tmp=inicializa();

        printf("VALOR DA FILA!\n");
        printf("###############################\n");
        while(f->inicio!=NULL){
            insere(tmp, f->inicio->info);
            printf("%d ", f->inicio->info);
            retira(f);
        }
        printf("\n###############################");

        while(tmp->inicio!=NULL){
            insere(f, tmp->inicio->info);
            retira(tmp);
        }
    }
}

void altera_inicio_fila(TFila *f, int novo){

    if(fila_vazia(f)) exit(1);

    else f->inicio->info=novo;

}