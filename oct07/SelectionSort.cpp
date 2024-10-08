#include <iostream>

void selection_sort(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size; ++i)
    {
        int min = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        std::swap(arr[i], arr[min]);
    }
}

void print(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 6, 3, 2, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    print(arr, size);
    return 0;
}