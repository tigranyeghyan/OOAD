#include <iostream>

void bubble_sort(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    for (int i = 0; i < size - 1; ++i)
    {
        bool flag = true;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag)
        {
            return; 
        }
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
    bubble_sort(arr, size);
    print(arr, size);
    return 0;
}