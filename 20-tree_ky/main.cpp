#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "base.h"
#include "Q01.h"
#include "Q02.h"
#include "Q03.h"
// #include "Q04.h"
// #include "Q05.h"
// #include "Q06.h"
// #include "Q07.h"

void treeNode(BinTN<string>* root){
    /** 
     *                          root             
     *                         /       \
     *                       A         B
     *                     /  \       /  \
     *                   C    D    E
     *                         
     */

    // *root = new BinTN<string>();
    // BinTN<string> A, B, C, D, E;
    // A.val = "A";
    // B.val = "B";
    // C.val = "C";
    // D.val = "D";
    // E.val = "E";
    
    // root->left = &A;
    // root->right = &B;
    // A.left = &C;
    // A.right = &D;
    // B.left = &E;
        
}


void testQ01(){}


void testQ02(){}


void testQ03(){}




    class BTree<T>
    {
        private T[] data;
        private int count = 0;
        /// <summary>
        /// 
        /// </summary>
        /// <param name="capacity">数组容量</param>
        public BTree(int capacity)
        {
            data = new T[capacity];
        }
 
        public void AddItem(T item)
        {
            if (data.Length <= count)
            {
                return;
            }
            data[count] = item;
            count++;
        }
 
        // 前序遍历
        public void PreorderTraversal()
        {
            PreorderTraversal(0);
        }
 
        private void PreorderTraversal(int index)
        {
            if (index >= data.Length) return;
            Console.Write(" " + data[index]);
            int num = index + 1;
            int left = 2 * num;
            int right = 2 * num + 1;
            PreorderTraversal(left - 1);
            PreorderTraversal(right - 1);
        }
 
 
        // 中序遍历
        public void SequentialTraversal()
        {
            SequentialTraversal(0);
        }
 
        private void SequentialTraversal(int index)
        {
            if (index >= data.Length) return;
            int num = index + 1;
            int left = num * 2;
            int right = num * 2 + 1;
 
            SequentialTraversal(left - 1);
            Console.Write(" " + data[index]);
            SequentialTraversal(right - 1);
 
        }
 
        // 后续遍历
        public void PostOrderTraversal()
        {
            PostOrderTraversal(0);
        }
 
        private void PostOrderTraversal(int index)
        {
            if (index >= data.Length) return;
            int num = index + 1;
            int left = num * 2;
            int right = num * 2 + 1;
 
            PostOrderTraversal(left - 1);
            PostOrderTraversal(right - 1);
            Console.Write(" " + data[index]);
        }
    }


int main(int argc, char const *argv[])
{
    
    return 0;
}

