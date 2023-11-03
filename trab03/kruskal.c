#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
    int u, v, weight;
} Edge;

/*Input já está ordenado como premissa, implementei a toa*/
/*int sortByWeight(Edge* elist, int nInputs)
{
    int i, j;
    Edge aux;

    for (i = 1; i < nInputs; i++) 
    {
        for (j = 0; j < nInputs - 1; j++) 
        {
             if (elist[j].weight > elist[j + 1].weight)
             {
                aux          = elist[j];
                elist[j]     = elist[j + 1];
                elist[j + 1] = aux;
             }
        }
    }

    return 0;
}*/

int cycleFilter(Edge *mstCandidate)
{



    return 0;
}

/* Recebe a lista de grafos do grafo e retorna o peso da "Minimum spanning tree". */
int kruskalMstWeight(Edge *elist, int numEdges)
{
    int weight = 0;
    Edge e;
    Edge* mstCandidate = NULL;
    Edge* mst = NULL;

    /* Iteração principal. Monta um candidato à MST aresta a aresta, verificando, a cada etapa, se criam ciclos */
    int i;
    int nEdgesOnMst = 0;
    int rc = 0;
    for (i = 0; i < numEdges; i++)
    {
        nEdgesOnMst++;

        e = elist[i];
        
        mstCandidate = (Edge*) realloc(mstCandidate, nEdgesOnMst * sizeof(Edge) );
        
        mstCandidate[i] = e;
        
        printf("%d %d %d\n", mstCandidate[i].u, mstCandidate[i].v, mstCandidate[i].weight);
    }

    for (i = 0; i < numEdges; i++)
        weight += mstCandidate[i].weight;

    free(mstCandidate);

    return weight;
}

int main() 
{

    int numVertices, numEdges;
    int *edges = NULL;
    int nInputs = 0;
    int MstWeight;

/*  Array final.  
    int edge[7][3] = { { 1, 2, 3 }, 
                       { 2, 3, 5 }, 
                       { 1, 3, 6 }, 
                       { 4, 5, 6 }, 
                       { 2, 3, 4 },
                       { 1, 4, 8 },
                       { 2, 4, 10 } }; */
  
    Edge e;
    Edge* elist = NULL;

    scanf("%d", &numVertices);

    while (scanf("%d %d %d", &e.u, &e.v, &e.weight) != EOF)
    {
        nInputs++;
        elist = (Edge*) realloc(elist, nInputs * sizeof(Edge) );
        /*Printf aresta*/
        elist[nInputs-1] = e;
    }

    MstWeight = kruskalMstWeight(elist, nInputs);

    printf("Minimum spanning forest weight: %d\n", MstWeight);

    free(elist);

    return 0; 
}
