#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "QBase.h"
#include "base.h"
#include "Q01.h"
#include "Q02.h"
#include "Q03.h"
#include "Q04.h"
#include "Q05.h"
#include "Q53.h"

void testGraph(){
    Graph* g = new Graph();
    g->testMatrix();
    // g->testTable();
}


void testQ01(){

}


void testQ02(){
    
}


void testQ03(){
    
}


void testQ04(){
    
}


void testQ05(){
    
}


void testQ53(){
    hw02();
    hw03();
    hw04();
}

int main(int argc, char const *argv[])
{
    testGraph();
    
    testQ01();
    testQ02();
    testQ03();
    testQ04();
    testQ05();
    testQ53();

    return 0;
}

