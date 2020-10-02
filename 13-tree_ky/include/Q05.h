#ifndef Q03_H
#define Q03_H

#include "base.h"
/**
 * (二叉)树应用四：哈夫曼树
 * https://blog.csdn.net/weixin_41427400/article/details/80383686
*/

struct Node
{
    char ch;
    int weight;
    Node* left;
    Node* right;

    Node(){
        left = NULL;
        right = NULL;
    }

    // 拷贝构造
    Node(const Node &p){
        ch = p.ch;
        weight = p.weight;
        
        if (p.left != NULL)
            left = p.left;
        else
        {
            leftNew = new Node();
            *left = *(leftNew.left);
        }
        
        if (p.right != NULL)
            right = p.right;
        else
        {
            rightNew = new Node();
            *right = *(rightNew.right);
        }
    }

    bool operator <= (const Node &p){
        return this->weight <= p.weight;
    }
}

class Huffman
{
public:
    Huffman();
    ~Huffman();


    // DisSt:展示编码表
    void disSt();

    // IsLeaf:判断对应节点是否为叶子节点
    bool isLeaf(Node* node);

    // GetFreq:获取权重数组
    void getFreq(int f);

    // BuildTree:根据权重数组构建哈夫曼树
    void buildTree();

    // Expend:根据哈夫曼树展开压缩文本
    string expend();

    // Compress:根据编码表压缩原始文本
    string compress();

private:
    // MakeEmpty:重置功能，重置哈夫曼树
    void makeEmpty();
    // BuildCode:根据哈夫曼树构建编码表
    void buildCode();

    const int R = 128;
    int *freq;  // 权重数组
    string *st;
    Node *root;
};

#endif