#include <stdio.h>
#include <string>
#include "DynamicArray.h"

#include <iostream>
using namespace std;

void test01(){
    Dynary_Array* arr = initArr();
    for(int i=0; i<10; i++){
        arr = addArr(arr, i);
    }

    printArr(arr);

    arr = removeArrByValue(arr, 5);
    printArr(arr);

    arr = editArr(arr, 3, 100);
    printArr(arr);
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}

