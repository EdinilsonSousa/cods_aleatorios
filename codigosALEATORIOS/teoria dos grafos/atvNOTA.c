#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int qtd_global[10001];

typedef struct vertice
{
    int visitado;
    int in;
    int out;
    int dist;
    struct lista *lista_adj;
} vertice;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

registro *aloca_registro();
lista *aloca_lista();
void push(vertice *v, int x);
void incluir_ordenado(lista *lista, int x);
void apaga_dist(vertice *vertices, int i);
void dfs(vertice *vertices, int x, int dist, int cont);

int main()
{
	int valor;
	
    vertice *vertices;
    int qtd_vert, qtd_aresta;
    bool resp;

    scanf("%d", &qtd_vert);
    scanf("%d", &qtd_aresta);

    vertices = (vertice*)calloc(10001,sizeof(vertice));


    for(int i=0;i<qtd_aresta;i+=1)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        push(&vertices[a],b);
        push(&vertices[b],a);
    }

    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    dfs(vertices, 1, 0, 0);
    resp = (vertices[x].in > vertices[y].in) && (vertices[x].out < vertices[y].out);
    
    if (resp) printf("Verdadeiro\n");
        else printf("Falso\n");
    return 0;
}


void incluir_ordenado(lista *lista, int x){
    if(lista == NULL)return;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if(lista->inicio == NULL)lista->inicio = novo;
    else {
        aux = lista->inicio;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    lista->qtd++;
}

registro *aloca_registro(){
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
}

lista *aloca_lista(){
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;  
}

void push(vertice *vertice, int valor){
    if(vertice->lista_adj == NULL) vertice->lista_adj = aloca_lista();
    incluir_ordenado(vertice->lista_adj, valor);
}

void apaga_dist(vertice *vertices, int i){
    int t = 0;

    for(i=0; i < 1001; i+=1){
        vertices[i].visitado = t;
    }
}

void dfs(vertice *vertices, int x, int dist, int cont){
    registro *aux;
    cont ++;
    vertices[x].visitado = 1;
    vertices[x].dist = dist;
    vertices[x].in = cont;

    if(vertices[x].lista_adj == NULL) return;

    aux = vertices[x].lista_adj->inicio;
    while(aux != NULL){
        if(vertices[aux->valor].visitado == 0){
            cont ++;
            vertices[x].out = cont;
            dfs(vertices, aux->valor, dist+1,cont);
        }
        aux = aux->prox;
    }
}

