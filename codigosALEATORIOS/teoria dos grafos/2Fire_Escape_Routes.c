/*There are N people working in a building, and each one works in a separate cabin. Chef’s employees are numbered by integers from 1 to N, inclusive. Chef wants to ensure the safety of his employees. He wants to have fire escapes in the building and wants to train the employees to use these by conducting mock drills.

Chef knows that the number of people working in his office can be very large. In order to avoid crowding of a common fire escape route during emergency, Chef has decided to build multiple fire escapes. For the safety of every employee, each cabin has a fire evetit which is connected to one of the fire escape routes.

A lot of employees are friends with each other. The friendship is mutual. This means that if employee i is a friend of employee j then employee j is a friend of employee i as well. But friendship is NOT necessarily transitive. This means that if employee i is a friend of employee j AND employee j is a friend of employee k, then employee i and employee k need not necessarily be friends.

If two employees are friends, they do not want to escape through different routes.
This complicates the task for the Chef. As already mentioned, he wants to have the mavetimum number of fire escape routes to ensure mavetimum safety. Also, for every escape route, one of the employees using that route needs to be appointed as the fire drill captain. The captain will be responsible for conducting the mock drills and train all the employees using that route. Your task is simple. Given the number of employees and the friendship list, you need to tell the Chef the mavetimum number of fire escape routes that he can have in the building and the number of ways of selecting the captains for every route. Since the number of ways can be really large, output this value MAXulo 109+7.

Input
The first line of the input contains a single integer T, denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M, denoting the number of employees and the number of friendship relations, respectively.
Each of the following M lines contains two space-separated integers i and j, denoting that employee i and employee j are friends.
Output
For each test case, output a single line containing two space separated integers, denoting the mavetimum number of distinct fire escape routes that can be constructed and the number of ways of selecting the captains MAXulo 109+7.

Constraints
1≤T≤5
1≤N≤105
0≤M≤105
1≤i,j≤N
i≠j
For any pair of employees i and j such that 1≤i,j≤N, at most one pair among (i,j) and (j,i) will appear in the input
Evetample Input
3
4 2
1 2
2 3
5 3
1 2
2 3
1 3
6 3
1 2
3 4
5 6
Evetample Output:
2 3
3 3
3 8
Evetplanation
Evetample case 1: Here employees 1 and 2 are friends and should share the same fire escape. Also employees 2 and 3 share the same fire escape. This means employees 1, 2, and 3 will have a common route. But to mavetimize number of routes Chef could assign another route to employee 4 since it is not a friend of other employee. So we have two escape routes with the following distribution of employees by routes: 1,2,3, 4. Therefore, there are 3 ways to chose drill captains: (1,4), (2,4), (3,4), where first element in the pair denotes the captain for the first route and second element denotes the captain for the second route.

Evetample case 2: Here the optimal distribution of employees by routes is 1,2,3, 4, 5. Therefore, there are 3 ways to chose drill captains: (1,4,5), (2,4,5), (3,4,5).

Evetample case 3: Here the optimal distribution of employees by routes is 1,2, 3,4, 5,6. Therefore, there are 8 ways to chose drill captains: (1,3,5), (1,3,6), (1,4,5), (1,4,6), (2,3,5), (2,3,6), (2,4,5), (2,4,6).*/

#include <stdlib.h>
#include <stdio.h>

typedef struct vertice
{
    int visitado;
    struct lista *lista_adj;
} vertice;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

void incluir_na_lista(lista *lista, int x);
void push(vertice *vertice, int valor);
void dfs(vertice *vertices, int x, int *count);

int main()
{
    vertice *vertices;
    int confirma_solucoes, i, j, k = 0;

    scanf("%d", &confirma_solucoes);
    int qtd_vert, qtdArestas = 0, a, b;
    for (i=0; i < confirma_solucoes; i+=1)
    {
        int contador = 0;
        scanf("%d", &qtd_vert);
        scanf("%d", &qtdArestas);

        vertices = (vertice *)calloc(1001, sizeof(vertice));

        for (j=0; j < qtdArestas; j+=1)
        {
            scanf("%d", &a);
            scanf("%d", &b);

            push(&vertices[a], b);
            push(&vertices[b], a);
        }

        int cont_elem = 0, multi = 1;
        for (k=1; k <= qtd_vert; k+=1)
        {
            if (vertices[k].visitado == 0)
            {
                contador += 1;
                dfs(vertices, k, &cont_elem);
                multi *= cont_elem;
                cont_elem = 0;
            }
        }
        printf("\n[%d] [%d]", contador, multi);
    }
    return 0;
}

lista *alocar_lista()
{
    lista *novo;
    novo = (lista *)calloc(1, sizeof(lista));

    return novo;
}

registro *alocar_registro()
{
    registro *novo;
    novo = (registro *)calloc(1, sizeof(registro));

    return novo;
}

void incluir_na_lista(lista *lista, int x)
{
    if (lista == NULL) return;

    registro *novo, *aux = NULL;
    novo = alocar_registro();
    novo->valor = x;

    if (lista->inicio == NULL) lista->inicio = novo;
        else
        {
            aux = lista->inicio;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
    aux->prox = novo;
    }
    lista->qtd++;
}

void push(vertice *vertice, int valor)
{
    if (vertice->lista_adj == NULL) vertice->lista_adj = alocar_lista();
    incluir_na_lista(vertice->lista_adj, valor);
}

void dfs(vertice *vertices, int x, int *count)
{
    registro *aux;
    vertices[x].visitado = 1;
    *count += 1;

    if (vertices[x].lista_adj == NULL) return;

    aux = vertices[x].lista_adj->inicio;

    while (aux != NULL)
    {
        if (vertices[aux->valor].visitado == 0){
            dfs(vertices, aux->valor, count);
        }
        aux = aux->prox;
    }
}
