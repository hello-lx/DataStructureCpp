#include <Q01.h>
#include <Q02.h>
// #include <Q03.hpp>
#include <Q03_.hpp>
#include <Q04.h>
#include <Q05.h>
#include <Q06.h>

void test01()
{
    binarySearch();
}

void test02()
{
    blockSearch();
}

void test03()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(data) / sizeof(int);
    
    CBTree<int>* cbTree = new CBTree<int>();
    for(int i=0; i<size; i++)
    {
        const int d = data[i];
        cbTree->insert(d);
    }

    cbTree->display();
    cbTree->remove(6);
    cout << endl;
    cbTree->display();
    cout << endl;
    cbTree->clear();
    cbTree->display();
}

void test04()
{
    
}

void test05()
{
    
}

void test06()
{
    
}

int main(int argc, char const *argv[])
{
    // test01();
    // test02();
    test03();
    test04();
    test05();

    // testLinkStack();
    // testLinkQueue();
    // testBiTree();
    return 0;
}

