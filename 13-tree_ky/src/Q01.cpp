#include "base.h"
#include "Q01.h"
using namespace std;

// ------------------------------------------------- Tree1 --------------------------------------------------------------
// 递归遍历
// void Tree1::preOrderRecursion(LCNode *node){  //前序递归遍历
//         if(node == NULL)
//                 return;
//         printf("%c", node->name);
//         preOrderRecursion(node->lChild);
//         preOrderRecursion(node->rChild);
// }

// void Tree1::midOrderRecursion(LCNode *node){  //中序递归遍历
//         if(node == NULL)
//                 return;
//         midOrderRecursion(node->lChild);
//         printf("%c", node->name);
//         midOrderRecursion(node->rChild);
// }

// void Tree1::postOrderRecursion(LCNode *node){  //后序递归遍历
//         if(node == NULL)
//                 return;
//         postOrderRecursion(node->lChild);
//         postOrderRecursion(node->rChild);
//         printf("%c", node->name);
// }

// // 非递归遍历
// void Tree1::preOrderNonRecursion(LCNode *node){

// }

// void Tree1::midOrderNonRecursion(LCNode *node){

// }

// void Tree1::postOrderNonRecursion(LCNode *node){

// }

// void Tree1::testTraversal(){

//         printf("前序遍历：\n");
//         cout << NLR << endl;
//         preOrderRecursion(root);
//         // preOrderNonRecursion(root);
//         printf("\n\n");

//         printf("中序遍历：\n");
//         cout << LNR << endl;
//         midOrderRecursion(root);
//         // midOrderNonRecursion(root);
//         printf("\n\n");

//         printf("后序遍历：\n");
//         cout << LRN << endl;
//         postOrderRecursion(root);
//         // postOrderNonRecursion(root);
//         printf("\n\n");
// }

