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

#include <stdio.h>
#include <stdlib.h>

#define MAX 100001
void def_uniao(int a, int b);
int enc_conjunto(int a);

int testa(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int vet[100001];
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		int a, b;
		int i, j;
		unsigned long prod;//permite usar o %lu
		int count;
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i+=1)
			vet[i] = i;
		for (i = 1; i <= m; i+=1)
		{
			scanf("%d %d", &a, &b);
			def_uniao(a, b);
		}
		for (i = 1; i <= n; ++i)
			enc_conjunto(i);
		qsort(vet + 1, n, sizeof(int), testa);
        //qsort é uma função em C utilizada para ordenação de arrays.
        /*exemplo:
        int i, val[] = { 15, 30, 10, 20, 25 };
        qsort(val, 5, sizeof(int), comparador);*/

		prod = 1UL;//1UL - unsigned long 
		count = 0;
		for (i = 1; i <= n; i+=1)
		{
			for (j = i + 1; j <= n; j+=1)
				if (vet[i] != vet[j]) break;
			prod = (prod * (j - i)) % MAX;
			count+=1;
			i = j-1;
		}
        
		printf("\n[%d] [%lu]", count, prod);
	}
	return 0;
}

void def_uniao(int a, int b)
{
	vet[enc_conjunto(a)] = enc_conjunto(b);
}

int enc_conjunto(int a)
{
	if (vet[a] != a) vet[a] = enc_conjunto(vet[a]);
	return vet[a];
}
