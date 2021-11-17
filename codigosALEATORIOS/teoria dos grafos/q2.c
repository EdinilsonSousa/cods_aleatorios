/*
Entrada:
A primeira linha countem a quantidade de casos de teste T.
A primeira linha de cada caso de teste countem dois inteiros separados por espaço N, M,
onde N representa a quantidade de vertices e M a quantidade de arestas.
cada uma das proximas M linhas countem dois inteiros separados por espaço X e Y, denotando que há uma ponte entre a ilha X e a ilha Y.

Saida:
Mostre a menor distancia para cada caso de teste.

exemplo de entrada:
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2

exemplo de saida:
2
2
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
    int visitado, distancia;
    struct lista *lista_adj;
}vertice;

typedef struct ListDup {
    struct registro * inicio, * fim;
}ListDup;

typedef struct lista {
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro {
    int valor;
    struct registro *prox;
}registro;

registro *aloca_registro();
lista *aloca_lista();
ListDup * aloca_fila();
int vazio(ListDup * fila);
int ORDlist(lista *l, int x);
void push(vertice *v, int x);
void push_fila(ListDup * fila, int x);
int Pop(ListDup * fila);
void bfs(vertice * vertices, int root, int N, int teste);


int main() {

    vertice *vertices;
    int teste = 0, cont=0, i = 0, j = 0;

    scanf("%d", &teste);
    for(i = 0; i < teste; i++){
        vertices = (vertice *) calloc(1001, sizeof(vertice));
        int qtd_vert, qtd_aresta;
        scanf("%d %d", &qtd_vert, &qtd_aresta);
        for(j = 0; j < qtd_aresta; j++){
            int a,b;
            scanf("%d %d", &a, &b);
            push(&vertices[a], b);
            push(&vertices[b], a);
        }
        
        bfs(vertices, 1, qtd_vert, teste);
    }
    return 0;
}

registro *aloca_registro() {
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

lista *aloca_lista() {
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

ListDup * aloca_fila() {
    ListDup * novo;
    novo = (ListDup*)calloc(1,sizeof(ListDup));
    return novo;
}

int vazio(ListDup * fila)
{
    if (fila==NULL)return 1;
    if (fila->inicio==NULL)return 1;
    return 0;
}

int ORDlist(lista *l, int x) {
    if (l == NULL) return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL) {
        l->inicio = novo;
    }
    else {
        int inserido = 0;
        
        aux = l->inicio;
        while (aux != NULL && !inserido) {

            if (aux->valor == novo->valor)return 0;

            if (aux->valor < novo->valor) {
                ant = aux;
                aux = aux->prox;
            } else {
                if (ant == NULL)
                    l->inicio = novo;
                else
                    ant->prox = novo;
                novo->prox = aux;
                inserido = 1;
            }
        }
        if (!inserido){
            ant->prox = novo;
            inserido = 1;
        }
    }
    l->qtd++;
    return 1;
}

void push(vertice *v, int x) {
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_lista();
    ORDlist(v->lista_adj, x);
}

void push_fila(ListDup * fila, int x) {   
    if (fila==NULL) return;
    
    registro * novo;
    novo = aloca_registro();
    novo->valor = x;

    if (fila->inicio==NULL) {
        fila->inicio = novo;
        fila->fim=novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int Pop(ListDup * fila) {
    int retorno;
    registro * aux;

    if (fila==NULL)return 0;
    if (fila->inicio==NULL)return 0;

    aux = fila->inicio;
    retorno = aux->valor;
    fila->inicio = aux->prox;

    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    return retorno;
}

void bfs(vertice * vertices, int root, int N, int teste){
    int retorno = 0, cont = 0, vet[teste], j=0, i=0;
    registro * aux;
    ListDup * fila;
    fila = aloca_fila();

    push_fila(fila,root);
    while(!vazio(fila)){

        cont++;
        retorno = Pop(fila);
        if (vertices[retorno].visitado==0) {
            vertices[retorno].visitado=1;

            aux = vertices[retorno].lista_adj->inicio;
            while(aux!=NULL) {
                if(aux->valor == N){
                    printf("%d\n", cont);
                    return;
                }

                push_fila(fila, aux->valor);
                aux = aux->prox;
            }
        }
    }
    
}
