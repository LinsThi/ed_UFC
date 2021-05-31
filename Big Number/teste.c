#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct estr 
{

    int valor;
    struct estr *prox;

} NO;
//Recebe um vetor de inteiros e devolve uma lista ligada de nos
NO* deVetorParaLista(int *v, int t)
{
    int i;
    NO* p = NULL;
    NO* a = NULL;//endereco do no anterior
    NO* lista = NULL;

    for(i = 0; i < t; i++ )
    {
        p = (NO*)malloc(sizeof(NO));
        p->valor = v[i];
        p->prox = NULL;

        if(i==0)
        {
            //copia primeiro endereco para variavel a ser retornada
            lista=p;
        }else{
            //se nao for o primeiro elemento copia endereco para 'prox' do no anterior
            a->prox=p;
        }
        a=p;
    }
    return lista;
}

void imprimir(NO *p)
{
    printf("\n");
    while(p!=NULL)
    {
        printf("%d",p->valor);
        printf("\n");
        p=p->prox;
    }
}
//libera memoria alocada
void limparLista(NO *p)
{
    NO *n;
    while(p!=NULL)
    {
        n=p->prox;
        free(p);
        p=n;
    }
}

int main()
{

    int v[] = {5,17,-2,55,1000};
    int t = (sizeof(v))/sizeof(int); //tamanho do vetor v
    NO* p=deVetorParaLista(v, t);

    imprimir(p);

    //limpar lista(somente depois de usa-la)
    limparLista(p);

    return 0;
}