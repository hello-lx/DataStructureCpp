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


void testQ03(){
    int a[] = {3, 5, 4, 1, 2, 6};
    /**
     *               3                                  3                                   1
     *             /   \                               / \                                   \ 
     *            1     5       == 删除节点5 ==>       1    4          == 或删除节点3 ==>        2
     *             \   / \                             \    \                                  \
     *              2 4   6                             2    6                                  5
     *                                                                                         / \
     *                                                                                        4   6
     */

    BSTree* tree = new BSTree();
    for(int i=0; i<6; i++)
        tree->insert(a[i]);
    
    cout << "先序遍历：" << endl;
    cout << "3 1 2 5 4 6" << endl;
    tree->preOrder(tree->getRoot());
    cout << endl << endl;

    cout << "后序遍历：" << endl;
    cout << "2 1 4 6 5 3" << endl;
    tree->postOrder(tree->getRoot());
    cout << endl << endl;

    cout << "中序遍历：" << endl;
    cout << "1 2 3 4 5 6" << endl;
    tree->inOrder(tree->getRoot());
    cout << endl << endl;


    BSTNode* n;
    cout << "最小值：" << endl;
    n = tree->minimum(tree->getRoot());
    if (n != nullptr)
        cout << n->key << endl << endl;
    else
        cout << "nullptr" << endl << endl;

    cout << "最大值：" << endl;
    n = tree->maximum(tree->getRoot());
    if (n != nullptr)
        cout << n->key << endl << endl;
    else
        cout << "nullptr" << endl << endl;

    cout << "search(6)：" << endl;
    n = tree->search(tree->getRoot(), 6);
    if (n != nullptr)
        cout << n->key << endl << endl;
    else
        cout << "nullptr" << endl << endl;

    cout << "前驱节点：" << endl;
    n = tree->predecessor(tree->getRoot());
    if (n != nullptr)
        cout << n->key << endl << endl;
    else
        cout << "nullptr" << endl << endl;

    BSTNode* dnode = tree->remove(tree->getRoot(), 5);
    cout << "删除节点" << dnode->key << "的前向遍历: " << endl;
    if (dnode) delete dnode;
    tree->preOrder(tree->getRoot());
    cout << endl << endl;

    cout << "销毁二叉树：" << endl;
    cout << tree->getRoot()->key << endl;
    tree->destroy(tree->getRoot());
    if(tree->getRoot())
        cout << tree->getRoot()->key << endl;
}


void testQ04(){}


void testQ05(){
    test05();
}


int main(int argc, char const *argv[])
{
    // testQ01();
    // testQ02();
    // testQ03();
    // testQ04();
    testQ05();

    return 0;
}

