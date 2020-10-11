#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Q01.h"
#include "Q02.h"
#include "Q03.h"
#include "Q04.h"
#include "Q05.h"
#include "Q53.h"
#include "QBase.h"

// template<typename  T> 
// void swap2(T& t1, T& t2) {
//     T tmpT;
//     tmpT = t1;
//     t1 = t2;
//     t2 = tmpT;
// }


void testGraph(){
    // Graph* g = new Graph();
    // g->testMatrix();
    // g->testTable();

    // testLinkQueue<int>();

    int x1=10, x2=20;
    cout << x1 << " " << x2 << endl;
    swap2<int>(x1, x2);
    cout << x1 << " " << x2 << endl;
}


void testQ01(){
    testDFSGT();
    testDFSGM();
    testBFSGT();
    testBFSGM();
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

