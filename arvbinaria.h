#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef long tipochave; 
typedef struct tiporegistro{
    tipochave chave;
}tiporegistro;

typedef struct tipono *tipoapontador;

typedef struct tipono{
    tiporegistro reg;
    tipoapontador esq,dir;
}tipono;

void inicializa(tipoapontador *dicionario){
    *dicionario = NULL;
}

void insere(tiporegistro x, tipoapontador *p){
    if(*p==NULL){
        *p=(tipoapontador)malloc(sizeof(tipono));
        (*p)->reg=x;
        (*p)->esq=NULL;
        (*p)->dir=NULL;
        return;}
    if(x.chave<(*p)->reg.chave){
        insere(x,&(*p)->esq);return;}
    if(x.chave>(*p)->reg.chave)
        insere(x,&(*p)->dir);
    else printf("\nErro: Registro ja existe na arvore\n");
    }

void pesquisa(tiporegistro *x, tipoapontador *p){
    
    if(*p==NULL){
        printf("\nErro: Registro nao esta presente na arvore\n");return; }
    if(x->chave<(*p)->reg.chave){
         pesquisa(x,&(*p)->esq);
        printf("Item encontrado, Item pesquisado %li", (*p)->esq->reg.chave);}//se o item esta a esquerda
    if(x->chave>(*p)->reg.chave){ pesquisa(x,&(*p)->dir);
          printf("Item encontrado, Item pesquisado  %li", (*p)->dir->reg.chave);//se o item esta a direita
    }
    else{ *x=(*p)->reg;
     printf("Item encontrado, Item pesquisado  %li", (*p)->reg.chave);  //Se o item for a raiz 
    }
    }

void antecessor(tipoapontador q, tipoapontador *r){
    if ((*r)->dir!=NULL){
        antecessor(q,&(*r)->dir);return;}
    q->reg=(*r)->reg;
    q=*r;
    *r=(*r)->esq;
    free(q);
}

void retira (tiporegistro x, tipoapontador *p){
    tipoapontador aux;
    if(*p==NULL){printf("\nErro: registro nao esta na arvore\n"); return;}
    if(x.chave<(*p)->reg.chave){retira(x,&(*p)->esq);return;}
    if(x.chave>(*p)->reg.chave){retira(x,&(*p)->dir);return;}
    if ((*p)->dir==NULL){
        aux=*p; *p=(*p)->esq;
        free(aux); return;
    }
    if((*p)->esq!=NULL){
        antecessor(*p,&(*p)->esq);return;
    }
    aux=*p; *p=(*p)->dir;
    free(aux);
    }


void imprime(tipoapontador p){
    if(p != NULL){
        imprime(p->esq);
        printf("\n%i", p->reg);
        imprime(p->dir);
    }
}