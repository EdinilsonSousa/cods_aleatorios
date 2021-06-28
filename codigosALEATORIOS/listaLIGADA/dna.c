#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct PILHA
{
	struct registro *comeco;
	int quant;
} PILHA;

typedef struct registro
{
	char num[1];
	struct registro *prox;
} registro;
/* ------------------------------------------------------ */
/* ------------------------------------------------------ */
void incluir(PILHA *pilha, char *num)
{
	registro *novo, *aux;
	novo = (registro *)malloc(sizeof(registro));
	strcpy(novo->num, num);
	if (pilha->comeco == NULL)
	{
		pilha->comeco = novo;
	}
	else
	{
		aux = pilha->comeco;
		novo->prox = aux;
		pilha->comeco = novo;
		++pilha->quant;
	}
}

char mostrar(PILHA *pilha)
{
	char carac[1];
	registro *aux;
    if (aux = pilha->comeco)
    {
        pilha->comeco = aux->prox;
    	strcpy(carac, aux->num);
    	--pilha->quant;
    }
	return *carac;
}

void comparar(PILHA *pilha, int tamanho)
{
	char aux1, aux2;
	int i, somad = 0;

	for (i=0; i < tamanho/2; ++i)
	{
		aux1 = mostrar(pilha);
		aux2 = mostrar(pilha);
		
		if ((aux1 == 'A' && aux2 == 'T')
		||
            (aux1 == 'T' && aux2 == 'A')
		||
			(aux1 == 'G' && aux2 == 'C')
		||
			(aux1 == 'C' && aux2 == 'G')
		||
			(aux1 == 'A' && aux2 == 'T'))
		{
			++somad;
		}
		else if ((aux1 == 'C' && aux2 == 'G')
		||
                 (aux1 == 'G' && aux2 == 'C'))
		{
			++somad;
		}
	}
	if (somad == tamanho/2)
    {
		puts("\nSIM\n");
	} 
    else
	{
		puts("\nNAO\n");
	}
}

int main()
{
	int i, j;
	int *vet;
	char nitrogenadas[2];
	PILHA *pilha;
    
	scanf("%d", &j);

	
	pilha = (PILHA *)malloc(sizeof(pilha));

	pilha->comeco = NULL;
	pilha->quant = 0;

	for (i = 0; i < j; ++i)
	{
		scanf("%s", nitrogenadas);
		incluir(pilha, nitrogenadas);
	}
	comparar(pilha, j);
	return 0;
}

/* 
Entrada
10
A T T A G C C G A T
Saída
SIM

Entrada
10
A T T T G C C G A T
Saída
NAO 

if((B=='0'||B=='1'||B=='2'||B=='3'||B=='4'||B=='5'||B=='6'||B=='7'||B=='8'||B=='9') exemplo
*/     
