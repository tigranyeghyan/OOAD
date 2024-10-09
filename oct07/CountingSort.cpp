#include <iostream>
#include <algorithm>



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

void counting_sort(int *arr, int size)
{
    if(!arr || size <= 0)
    {
        return;
    }
    int min = *std::min_element(arr, arr + size);
    int max = *std::max_element(arr, arr + size);
    int range = max - min + 1;
    int *countArray = new int[range];
    for(int i = 0; i < size; ++i)
    {
        countArray[arr[i] - min]++;
    }
    for(int i = 1; i < range; ++i)
    {
        countArray[i] += countArray[i - 1];
    }

    int *outputArray = new int[size];
    for(int i = 0; i < size; ++i)
    {
        outputArray[countArray[arr[i] - min] - 1] = arr[i];
        countArray[arr[i] - min]--;
    }
    for(int i = 0; i < size; ++i)
    {
        arr[i] = outputArray[i];
    }
    delete []countArray;
    delete []outputArray;
}

int main()
{           
    int arr[] = {1, 2, 6, 3, 2, 5, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    counting_sort(arr, size);
    print(arr, size);
    return 0;
}