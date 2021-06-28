#include <stdio.h>
#include <stdlib.h>

void mostrar(int *vet, int TAM)
{
    int j=0, i=0, aux=0;

    for(i=0; i<TAM; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
           if(vet[i] > vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
				vet[j] = aux;
            }
        }
    }
}

int fila(int *vet, int TAM)
{
    int i=0, j=0, soma=0;
    int aux=0; 

    for(i=0; i<TAM; i++)
    {
        soma = 0;
        for(j=0; j<i; j++)
        {
            soma += vet[j];
        }
        if(soma<=vet[i])
        {
            ++aux;
        }
    }
    return aux;
}

int main() 
{
    int j, i, aux;
    int *pont; 
    scanf("%d", &j);
	pont = (int *)malloc(sizeof(int)*j);

    for(i=0; i<j; i++)
    {
        scanf("%d", &pont[i]);
    }
    mostrar(pont, j);
    
    aux = fila(pont, j);
    printf("\n|%d|\n", aux);
    return 0;
}

/* C Fila
ENTRADA
5
15 2 1 5 3
SAÍDA
4 */
