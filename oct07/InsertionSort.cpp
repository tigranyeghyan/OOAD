#include <iostream>

void insertion_sort(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    for (int i = 1; i < size; ++i)
    {
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, size);
    print(arr, size);
    return 0;
}