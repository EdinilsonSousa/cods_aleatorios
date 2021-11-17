/*
implemente um programa que receba do usuario um numero N que representa a quantidade de cidades enumeradas de 1 ate N e um numero M que representa
a quantidade de estradas que conectam 2 cidades.
A seguir leia M pares de cidades(X,Y), onde cada par representa uma estrada que conecta a cidade X a cidade Y e mostre na tela quais estradas nao 
podem entrar em reforma (serem excluidas) sem que atrapalhe joao atravessar por todas as cidades partindo da cidade 1.

exemplo de entrada:
4 4
1 2
2 3
3 4
4 2

saida:
a estrada de que conecta a cidade 1 a 2 nao pode entrar em reforma.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct registro {
    int valor;
    struct registro *prox;
} registro;

typedef struct lista {
    int qtd;
    struct registro *inicio;
} lista;

typedef struct vertice {
    int in, lower, visitado;
    struct lista *lista_adj;
} vertice;

lista *aloca_Lista() {
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));
    return novo;
}

registro *aloca_Registro() {
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));
    return novo;
}

void push(vertice *v, int x);
void bfs(vertice *vertices, int x, int noPAI);


int count = 1;
int incluir(lista *lista, int x) {
    if (lista == NULL) return 0;

    registro *novo, *aux = NULL, *ant = NULL;
    novo = aloca_Registro();
    novo->valor = x;

    if (lista->inicio == NULL){
        lista->inicio = novo;
    } else {
        int inserido = 0;
        
        aux = lista->inicio;
        while (aux != NULL && !inserido) {

            if (aux->valor == novo->valor) return 0;

            if (aux->valor < novo->valor) {
                ant = aux;
                aux = aux->prox;
            } else if (ant == NULL){
                    lista->inicio = novo;
                } else{
                    ant->prox = novo;
                }
                novo->prox = aux;
                inserido = 1;
        }
        if (!inserido)
            ant->prox = novo;
            inserido = 1;
    }
    lista->qtd++;
    return 1;
}

void push(vertice *v, int x) {
    if (v->lista_adj == NULL)
        v->lista_adj = aloca_Lista();
    incluir(v->lista_adj, x);
}

int main(int *argc, char *argv[]) {

    vertice *vertices;
    int qtdVertices = 0, qtdArestas = 0, i = 0, j = 0;

    vertices = (vertice *) calloc(1001, sizeof(vertice));
    
    scanf("%d %d", &qtdVertices, &qtdArestas);

    for(j = 0; j < qtdArestas; j++){
        int a,b;
        scanf("%d %d", &a,&b);
        push(&vertices[a], b);
        push(&vertices[b], a);
    }
    bfs(vertices, 1, -1);
    return 0;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void bfs(vertice *vertices, int x, int noPAI) {
    registro *aux;
    vertices[x].visitado = 1;
    vertices[x].in = count;
    vertices[x].lower = count;
    count++;

    if (vertices[x].lista_adj == NULL) return;

    aux = vertices[x].lista_adj->inicio;

    while (aux != NULL) {
        if (aux->valor != noPAI){
            if (vertices[aux->valor].visitado == 1) {
                vertices[x].lower = min(vertices[x].lower, vertices[aux->valor].in);
            } else {
                bfs(vertices, aux->valor, x);

                if (vertices[aux->valor].lower > vertices[x].in) {
                    printf("\nA estrada que conecta as cidades %d e %d não pode entrar em reforma ", x, aux->valor);
                }

                vertices[x].lower = min(vertices[x].lower, vertices[aux->valor].lower);
            }
        }
        aux = aux->prox;
    }
}
