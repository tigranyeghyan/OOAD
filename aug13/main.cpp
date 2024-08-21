#include "DynamicArray.h"

int main()
{
    DynamicArray arr1;
    arr1.push(5);
    arr1.push(6);
    arr1.push(7);
    arr1.push(8);
    arr1.push(9);
    arr1.push(1);

    DynamicArray arr2(arr1);
    arr2.display();

    return 0;
}
