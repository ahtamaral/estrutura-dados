#include <stdio.h> 
#include <stdlib.h> 

typedef struct {
    int u, v, weight;
} Edge;

int main() 
{

    int numVertices, numEdges;
    int *edges = NULL;
    int nInputs = 0;

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
        elist[nInputs-1] = e;
    }

    int i = 0;
    for (i = 0; i < nInputs; i++)
        printf("%d - %d: %d\n", elist[i].u, elist[i].v, elist[i].weight);


    return 0; 
}
