#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "base.h"

void testGraph(){
    Graph* g = new Graph();
    // g->testMatrix();
    g->testTable();
}


int main(int argc, char const *argv[])
{
    testGraph();
    return 0;
}

