#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utilitário para trocar os valores de duas variáveis
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Particiona o array e retorna indice do pivô
int particiona(int arr[], int menor, int maior) 
{
    // Pivô escolhido aleatoriamente.
    srand(time(NULL));
    int randomIndex = menor + rand() % (maior - menor + 1);
    swap(&arr[randomIndex], &arr[maior]);

    int pivot = arr[maior];
    int i = (menor - 1);

    for (int j = menor; j <= maior - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[maior]);
    return (i + 1);
}

// QuickSort recursivo
void quickSort(int arr[], int menor, int maior) 
{
    if (menor < maior) 
    {
        int pivotIndex = particiona(arr, menor, maior);

        quickSort(arr, menor, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, maior);
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int num;

    /* Lê input do stdin (ou arquivo) até encontrar o EOF.
        Aloca dinamicamente o array durante a leitura. */
    while (scanf("%d", &num) != EOF) 
    {
        size++;
        arr = (int *)realloc(arr, size * sizeof(int));
        arr[size - 1] = num;
    }

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size-1; i++) 
        printf("%d\n", arr[i]);
    printf("%d", arr[size-1]);

    free(arr);

    return 0;
}
