/*
Pergunta 1
Faça um programa que disponibilize 3 opções para o usuário
1 - Incluir na Fila
2 - Chamar alguém da fila
3 - Sair.
Implemente uma lógica de fila utilizando obrigatoriamente uma estrutura de vetor.*/

#include <stdio.h>
#include <stdlib.h>
#define tam 10
int giga[tam];


int adicionar_fila(int num);
int mostra_e_remove();
int pilha_semNADA();
int fila_cheia();
void mostra();
void menu_opcoes();

int qtd = 0;
int main()
{
    menu_opcoes();
    return 0;
}

int adicionar_fila(int num)
{
    if (fila_cheia())
    {
        return 0;
    }
    else
    {
        giga[qtd] = num;
        qtd+=1;
        return 1;
    }
}

int pilha_semNADA()
{
    if (qtd == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int fila_cheia()
{
    if (qtd == tam)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostra()
{
    int i;
    puts("\n\t|-|Pilha|-|");
    for (i = tam-1; i >= 0; i--)
    {
        printf("\n\t->[ %d ]<-", giga[i]);
    }
    puts("\n\t^(Pilha)^");
    puts("\n");
}

int mostra_e_remove()
{
    int num;

    if (pilha_semNADA())
    {
        return -1;
    }
    else
    {
        num = giga[qtd];
        giga[qtd] = -1;
        qtd--;
        return num;
    }
}

void menu_opcoes()
{
    int opcao, numero, voltar;

    do
    {
        mostra();
        puts("\n[1] Adicionar numero na Lista: ");
        puts("\n[2] Chamar alguém da pilha: ");
        puts("\n[3] Sair");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            puts("\nEscreva um valor: ");
            scanf("%d", &numero);
            if (adicionar_fila(numero))
            break;
        case 2:
            if (pilha_semNADA())
            {
                puts("\n Sua pilha esta vazia");
            }
            else
            {
                voltar = mostra_e_remove();
                printf("\n Chamei esse -> |%d|", voltar);
            }

            break;
        case 3:
            puts("\n Deixando o programa agora, tchau!");
            break;
        default:
            puts("\n Opcao nao exitente no menu, leia novamente!!");
        }
    } 
    while (opcao != 3);
}
