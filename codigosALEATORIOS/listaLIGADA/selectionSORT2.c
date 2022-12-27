/*Implemente o algoritmo SelectionSort e:

a) mostre na tela o tempo gasto para ordenar um vetor de tamanho 150.000 totalmente embaralhado;

b) mostre o tempo gasto para ordenar o mesmo vetor com apenas 10 números fora da ordem.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 150000

void selection_sort(int *vet, int tam)
{
int alfa, beta, menor, help;
clock_t start, end;
start = clock();
for(alfa=0; alfa<tam-1; alfa++)
{
menor = alfa;
for(beta=alfa+1; beta<tam; beta++)
{
if(vet[beta] < vet[menor])
{
menor = beta;
}
}
help = vet[alfa];
vet[alfa] = vet[menor];
vet[menor] = help;
}
end = clock();
printf("Tempo gasto para ordenar o vetor: %f segundos\n", (double)(end - start)/CLOCKS_PER_SEC);
}

int main()
{
int *vet;
int i;
vet = (int *)malloc(sizeof(int) * SIZE);
// Inicializa o vetor com valores aleatórios
srand(time(NULL));
for(i=0; i<SIZE; i++)
{
    vet[i] = rand();
}

printf("Vetor de tamanho 150.000 totalmente embaralhado:\n");
selection_sort(vet, SIZE);

// Insere 10 números fora da ordem
for(i=0; i<10; i++)
{
    vet[SIZE - 1 - i] = rand();
}

printf("Vetor de tamanho 150.000 com apenas 10 números fora da ordem:\n");
selection_sort(vet, SIZE);

return 0;
}
