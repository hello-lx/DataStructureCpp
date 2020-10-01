#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "base.h"
#include "Q01.h"
#include "Q02.h"
#include "Q03.h"
#include "Q04.h"
#include "Q05.h"

void testBase()
{
    Tree1* tree = new Tree1();
    free(tree);
}

void testQ01()
{
    Tree1* tree = new Tree1();
    tree->testTraversal(tree->getRoot());
    // tree->testSearchNode();
}


void testQ02()
{
    TreeApp2 treeApp2;
    treeApp2.test();
}


void testQ03(){}


void testQ04(){}


void testQ05(){}


int main(int argc, char const *argv[])
{
    // testQ01();
    testQ02();
    // testQ03();
    // testQ04();
    // testQ05();

    return 0;
}

