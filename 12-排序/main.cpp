#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "_1bubble.h"
#include "_2insert.h"
#include "_3shell.h"
#include "_4quick.h"
#include "_5merge.h"
#include "_6heap.h"


int main(int argc, char const *argv[])
{
    testBubbleSort();
    testInsertSort();
    testShellSort();
    testQuickSort();
    testMergeSort();
    testHeapSort();
    return 0;
}

