#include <stdio.h> 
#include <stdlib.h> 
  
/* Uso do algoritmo Union Find para detectar os ciclos.
https://en.wikipedia.org/wiki/Disjoint-set_data_structure*/

int findParent(int parent[], int component) 
{ 
    if (parent[component] == component) 
        return component; 
  
    return parent[component] 
           = findParent(parent, parent[component]); 
} 
  
void conjuntoUniao(int u, int v, int parent[], int rank[], int n) 
{ 
    u = findParent(parent, u); 
    v = findParent(parent, v); 
  
    if (rank[u] < rank[v]) { 
        parent[u] = v; 
    } 
    else if (rank[u] > rank[v]) { 
        parent[v] = u; 
    } 
    else { 
        parent[v] = u; 
        rank[u]++; 
    } 
}
  
void kruskal(int n, int edge[n][3]) 
{ 
    int parent[n]; 
    int rank[n]; 
  
    for (int i = 0; i < n; i++) 
    { 
        parent[i] = i; 
        rank[i] = 0; 
    }  
   
    int mstWeight = 0; 
    int v1, v2, wt;

    for (int i = 0; i < n; i++) 
    { 
        v1 = findParent(parent, edge[i][0]); 
        v2 = findParent(parent, edge[i][1]); 
        wt = edge[i][2]; 
  
        if (v1 != v2)
        { 
            conjuntoUniao(v1, v2, parent, rank, n); 
            mstWeight += wt; 
        } 
    } 
  
    printf("%d\n", mstWeight); 
} 
  
int main() 
{
    int nVertices;

    /*Programa só funciona para até 100 arestas.*/
    int elist[100][3];

    scanf("%d", &nVertices);

    int nEdges = 0;

    /* Lê aresta por aresta, já atribuindo às posições na matriz.*/
    while (scanf("%d %d %d", &elist[nEdges][0], &elist[nEdges][1], &elist[nEdges][2]) != EOF) 
        nEdges++;
  
    kruskal(nEdges, elist);
  
    return 0; 
}