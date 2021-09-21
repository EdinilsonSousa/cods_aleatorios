#include <iostream>
#include <vector>
/*
There are N countries {1,2,3,4...N} and N-1 roads(i.e depicting a tree)
Bishu lives in the Country 1 so this can be considered as the root of the tree.
Now there are Q girls who lives in various countries (not equal to 1).
All of them want to propose Bishu. But Bishu has some condition.
He will accept the proposal of the girl who lives at minimum distance from his country.
Now the distance between two countries is the number of roads between them.
If two or more girls are at the same minimum distance then he will accept the proposal of the girl who lives in a country with minimum id.
No two girls are at same country. 
input: First line consists of N.i.e number of countries Next N-1 lines follow the type u v which denotes there is a road between u and v. 
ThenNext line consists of Q Next Q lines consists of x where the girls live.

Output: Print the id of the country of the girl who will be accepted.

Help Him!!!
contraints: 2<=N<=1000  1<=u.v<=N  1<=Q<=(N=1)

SAMPLE INPUT
6
1  2
1  3
1  4
2  5
2  6
4
5
6
3
4

SAMPLE OUTPUT
3
*/
using  namespace::std;
vector<int> vet[1000];

int visited[1000];
int dist[1000];

void DFS(int node,int distance){
    if(visited[node]==0){
        
        visited[node]=1;
        dist[node]=distance;
        
        for(int child:vet[node])
            DFS(child, dist[node]+1);
    }
}

int main() {

    int MAXgirl=100, MINdist=100;
    vector<int> girls;
    
    int N, u, v, i, j;
    cin>>N;
    
    for(i=1;i<=N-1;i++){
        cin>>u>>v;
        vet[u].push_back(v);
        vet[v].push_back(u);
    }
    
    int Q;
    cin>>Q;
    int girl;
    
    for(i=1;i<=N;i++){
        DFS(1,0);
    }

    for(j=1;j<=Q;j++){
        cin>>girl;
        if(girl<=MAXgirl && dist[girl]<=MINdist){
            MINdist=dist[girl];
            MAXgirl=girl;
        }
        
    }
    cout<<"toppp ->" <<MAXgirl;
}
