/*
ENTRADA
A primeira linha do seu programa receberá um numero Q referente a quantidade de vertices desse grafo, na segunda linha voce recebera um numero V referente a quantidade de arestas desse grafo.
Nas proximas V linhas voce recebera dois numeros separados por espaço simbolizando uma aresta do grafo.
Apos isso voce recebera um numero C, que consiste na quantidade de consultas que voce devera fazer, nas proximas C linhas voce recebera dois numeros separados por espaço indincando dois vertices desse grafo.

SAIDA
Para cada consulta entre dois nós voce devera apresentar a dist entre os dois nós.
OBS: é garantido que o numero de arestas é igual ao numero de vertices menos 1 e que só existe um componente nesse grafo.

ENTRADA
6
5
1 2
1 3
1 4
3 5
3 6
3
1 5
5 2
4 2

SAIDA
2
3
2

*/
#include <stdlib.h>
#include <stdio.h>

typedef struct vertice{
    int visitado;
    int dist;
    struct lista *lista_adj;
} vertice;

typedef struct registro{
    int valor;
    struct registro *prox;
} registro;

typedef struct lista{
    int qtd;
    struct registro *inicio;
} lista;

lista *alocar_lista();
registro *alocar_registro();
void incluir_na_lista(lista *lista, int valor);
void push(vertice *vertice, int valor);
void LIMdist(vertice *vertices);
void dfs(vertice *vertices, int x, int dist); 

#define MAX 10001

int main(){

    vertice *vertices;

    int qtd_vertices, qtd_arestas; 
    scanf("%d", &qtd_vertices);
    scanf("%d", &qtd_arestas);

    vertices = (vertice *)calloc(MAX, sizeof(vertice));

    for(int i = 0; i < qtd_arestas; i+=1){
        int a,b;
        scanf("%d", &a);
        scanf("%d", &b);
        push(&vertices[a], b);
        push(&vertices[b], a);
    }

    int qtd_consultas;
    scanf("%d", &qtd_consultas);
    int contador[qtd_consultas];
    for(int j = 0; j < qtd_consultas; j+=1){
        int c, d;
        scanf("%d", &c);
        scanf("%d", &d);

        dfs(vertices, c, 0);     
        contador[j]= vertices[d].dist;
        //printf("\n\t%d\n ", vertices[d].dist);

        LIMdist(vertices);
    }
    int k;
    for(k = 0; k<qtd_consultas; k+=1){
        printf("%d\n", contador[k]);
    }    


    return 0;
}

lista *alocar_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista)); 
    return novo;  
}

registro *alocar_registro(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
}

void LIMdist(vertice *vertices){
    for(int i=0; i < MAX; i+=1) vertices[i].visitado = 0;
}

void incluir_na_lista(lista *lista, int valor){
    if(lista == NULL) return;  

    registro *novo, *aux = NULL, *ant = NULL;
    novo = alocar_registro();
    novo->valor = valor;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }else {
        aux = lista->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    lista->qtd++;
}

void push(vertice *vertice, int valor){
    if(vertice->lista_adj == NULL) vertice->lista_adj = alocar_lista();
    incluir_na_lista(vertice->lista_adj, valor);
}


void dfs(vertice *vertices, int x, int dist){
    registro *aux;
    vertices[x].visitado = 1;
    vertices[x].dist = dist;

    if(vertices[x].lista_adj == NULL) return;

    aux = vertices[x].lista_adj->inicio;
    while(aux != NULL){
        if(vertices[aux->valor].visitado == 0) dfs(vertices, aux->valor, dist+1);
        aux = aux->prox;
    }
}
