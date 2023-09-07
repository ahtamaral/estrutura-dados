#include <iostream>
#include <vector>

// Função de particionamento do qsort
int partition(std::vector<int>& arr, int low, int high) 
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void qsort(std::vector<int>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pivotIdx = partition(arr, low, high);

        qsort(arr, low, pivotIdx - 1);
        qsort(arr, pivotIdx + 1, high);
    }
}

int main() 
{
    std::vector<int> numbers;
    int num;

    // Lê stdin até o EOF
    while (std::cin >> num) 
    {
        numbers.push_back(num);
    }
    //Ordena vetor numbers
    qsort(numbers, 0, numbers.size() - 1);

    // Printa resultado
    for (int num : numbers) 
        std::cout << num << " ";

    return 0;
}
