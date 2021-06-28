#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *final;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
}registro;

lista *alocar_lista();
registro *aloca_registro(int valor);
void mostra_fila(lista *fila);
void incluir_fila_pares(lista *fila, int valor);
void incluir_fila_impares(lista *fila, int valor);

int main() 
{
    lista *fila_pares, *fila_impares;   
    int i=0, N=0, *vet, aux=0;

    fila_pares   =  alocar_lista();
    fila_impares =  alocar_lista();
    
    scanf("%d", &N);

    vet = (int *)malloc(sizeof(int)*N);
    
    for(i=0; i<N; i++)
    {
        scanf("%d", &aux);
        
        if(aux%2 == 0)
        {
            incluir_fila_pares(fila_pares, aux);
        }
        else
        {
            incluir_fila_impares(fila_impares, aux);
        }
    }

    mostra_fila(fila_pares);
    mostra_fila(fila_impares);
}

lista *alocar_lista()
{
    lista *a;

    a = (lista*)malloc(sizeof(lista));
    a->qtd = 0;
    a->inicio = NULL;
    a->final = NULL;

    return a;
}

registro *aloca_registro(int valor)
{
    registro *a;

    a = (registro *)malloc(sizeof(registro));
    a->valor = valor;
    a->prox = NULL;
    a->ant = NULL;

    return a;
}

void mostra_fila(lista *fila)
{
    int teste=0;
    registro *aux;

    aux = fila->inicio;
    while(aux != NULL)
    {
        printf("%d", aux->valor);
        aux = aux->prox;

        if(aux != NULL)
        {
            printf(" ");
        }
        else
        {
            printf("\n");
        }
    }
}

void incluir_fila_pares(lista *fila, int valor)
{
    registro *novo, *aux;
    
    novo = aloca_registro(valor);

    if(fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->final = novo;
    }
    else if(novo->valor < fila->inicio->valor)
    {
        novo->prox        = fila->inicio;
        fila->inicio->ant = novo;
        fila->inicio      = novo;
    }
    else if(novo->valor > fila->final->valor)
    {
        fila->final->prox = novo;
        novo->ant         = fila->final;
        fila->final       = novo;
    }
    else
    {
        aux = fila->inicio;
        while(novo->valor > aux->valor)
        {
            aux = aux->prox;
        }
        novo->prox     = aux;
        novo->ant      = aux->ant; 
        aux->ant->prox = novo;
        aux->ant       = novo;
    }

    fila->qtd++;
}

void incluir_fila_impares(lista *fila, int valor)
{
    registro *novo, *aux;
    
    novo = aloca_registro(valor);

    if(fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->final = novo;
    }
    else if(novo->valor > fila->inicio->valor)
    {
        aux = fila->inicio;

        novo->prox        = fila->inicio;
        fila->inicio->ant = novo;
        fila->inicio      = novo;
    }
    else if(novo->valor < fila->final->valor)
    {
        fila->final->prox = novo;
        novo->ant         = fila->final;
        fila->final       = novo;
    }
    else
    {
        aux = fila->inicio;
        while(novo->valor < aux->valor)
        {
            aux = aux->prox;
        }
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant->prox = novo;
    }

    fila->qtd++;
}
/* Entrada
10
4 32 34 543 3456 654 567 87 6789 98

Saída
4 32 34 98 654 3456
6789 567 543 87*/
