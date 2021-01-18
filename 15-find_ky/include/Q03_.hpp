#pragma once

/* 平衡二叉树、B树、B+树、B*树介绍: https://zhuanlan.zhihu.com/p/27700617

 * B树: https://blog.csdn.net/liu1064782986/article/details/7481011

1）每个结点x有如下域：
    a）n[x]，当前存储在结点x中的关键字个数； 
    b）n[x]个关键字本身，以非降序存放，因此key 1 [x]≤key 2[x]≤…≤key n[x][x] ；
    c）leaf[x]，是一个布尔值，如果x是叶子结点的话，则它为TRUE，如果x为一个内结点，则它为FALSE。
2）每个内结点x还包含n[x]+1个指向其子女的指针c 1[x]，c 2[x]，…，c n[x]+1[x]。叶结点没有子女，故它们
    的c i域无定义。
3）各关键字Keyi[x]对存储在各子树中的关键字范围加以分隔：如果ki为存储在以ci[x]为根的子树中的关键字，则
    k 1≤key 1[x]≤k 2≤key 2[x]≤…≤key n[x][x]≤k n[x]+1
4）每个叶结点具有相同的深度，即树的高度h。
5）每一个结点能包含的关键字数有一个上界和下界。这些界可用一个称作B树的最小度数（即一个结点中可指向的孩子结点个数）
    的固定整数t≥2来表示。


插入新节点
    向B树中插入关键字，同二叉查找树中插入一个关键字类似，要查找插入新关键字的叶子结点位置。
    因为不能把关键字插入到一个已满的叶子结点中，故需要将一个已满的结点按其中间关键字分裂成两个结点，
    中间关键字被提升到该结点的父结点中。但是这种满结点的分裂动作会沿着树向上传播。为了解决这个问题，
    可以采取这样一种策略：当沿着树根往下查找新关键字所属位置时，就沿途分裂遇到的每个满结点。
    因此，每当要分裂一个满结点时，就能确保它的父结点不是满的。

B树中删除关键字
 B树上的删除操作与插入操作类似，只是稍微复杂点，因为一个关键字能够从任意一个结点中删除，而不只是叶结点。就要我们必须保证一个结点不会因为插入而变得太大一样，必须保证一个结点不会因为删除而变得太小。下面，大致描述一下删除关键字的各种情况：
1）如果关键字k在结点x中而且x是个叶结点，则从x中删除k。
2）如果关键字k在结点x中而且x是个内结点，则作如下操作：
      a）如果结点x中前于k的子结点y包含至少t个关键字，则找出k在以y为根的子树中的前驱k‘。递归的删除k’，并在x中用k‘取代k。
      b）对称地，如果结点x中位于k之后的子结点z包含至少t个关键字，则找出k在以z为根的子树中的后继k’。递归的删除k‘，并在x中使用k’取代k。 
      c）否则，如果y和z都只有t-1个关键字，则将k和z中所有关键字合并进y，使得x失去k和指向z的指针，这使y包含2t-1个关键字。然后，释放z并将k从y中递归删除。
3）如果关键字k不在内结点x中，则确定包含k的正确的子树的根ci[x]。如果ci[x]只有t-1个关键字，执行步骤3a或3b以保证我们降至一个包含至少t个关键字的结点。然后，通过对x的某个合适的子结点递归而结束。
      a）如果ci[x]只包含t-1个关键字，但它的一个相邻兄弟结点包含至少t个关键字，则将x中的某一个关键字降至ci[x]中，将ci[x]的相邻左兄弟或右兄弟中的某一关键字升至x，将该兄弟中合适的子结点指针移到ci[x]中，这样使得ci[x]增加一个额外的关键字。
      b）如果ci[x]以及ci[x]的所有相邻兄弟结点都只包含t-1个关键字，则将ci[x]与任意一个兄弟合并，则将x的一个关键字移至新合并的结点，使之成为新结点的中间关键字。 
*/

template<class T>
class CBTree
{
private:
    static const int M = 3;
    static const int KEY_MAX = 2*M - 1;
    static const int KEY_MIN = M - 1;
    static const int CHILD_MAX = KEY_MAX + 1;
    static const int CHILD_MIN = KEY_MIN + 1;
    
    struct Node
    {
        bool isLeaf;  // 是否是叶子节点
        bool keyNum;
        T keyValue[KEY_MAX];
        Node* pChild[CHILD_MAX];
        
        Node(bool b=true, int n=0): isLeaf(b), keyNum(n) {}
    };

public:
    CBTree(){ m_pRoot = nullptr; }

    ~CBTree(){ clear(); }

    bool ~CBTree()
    {
        clear();
    }

    bool insert(const T &key)
    {
        if(contain(key))  // 检查key值时候存在树中
            return false;
        else
        {
            if (m_pRoot == nullptr)
            {
                m_pRoot = new Node();
            }
            if (m_pRoot->keyNum == KEY_MAX)
            {}
            insertNonFull(m_pRoot, key);
            return true;
        }
    }

    bool remove(const T& key)
    {
        if(!search(key))
        {
            return false;
        }

        // 特殊情况处理
        if(m_pRoot->keyNum == 1)
        {
            if(m_pRoot->isLeaf)
            {
                clear();
                return true;
            }
            else
            {
                Node *pChild1 = m_pRoot->pChild[0];
                Node *pChild2 = m_pRoot->pChild[1];
                if (pChild1->keyNum==KEY_MIN && pChild2->keyNum==KEY_MIN)
                {
                    mergeChild(m_pRoot, 0);
                    deleteNode(m_pRoot);
                    m_pRoot = pChild1;
                }
            }
        }

        recursive_remove(m_pRoot, key);
        return true;
    }

    bool contain(const T &key) const
    {
        if(search(m_pRoot, key))
            return false;
        return true;
    }

    void clear(){
        recursive_clear(m_pRoot);
        m_pRoot = nullptr;
    }

private:
    void recursive_clear(Node *pNode){
        if(pNode != nullptr)
        {
            if(!pNode->isLeaf)
            {
                for(int i=0; i<=pNode->keyNum; i++)
                    recursive_clear(pNode->pChild[i]);
            }
            deleteNode(pNode);
        }
    }

    void deleteNode(Node *&pNode){
        if(pNode != nullptr)
        {
            delete pNode;
            pNode = nullptr;
        }
    }

    bool search(Node *pNode, const T &key) const{
        if(pNode == nullptr)
            return false;
        
        int i;
        //找到使key<=pNode->keyValue[i]成立的最小下标i
        for(i=0; i<pNode->keyNum && key>*(pNode->keyValue+i); i++){}

        if(i<pNode->keyNum && key == pNode.keyValue[i])
            return true;
        else
        {
            if(pNode->isLeaf)
                return false;
            else
                search(pNode->pChild[i], key);
        }
    }

    void splitChild(Node *pParent, int nChildIndex, Node* pChild){
        Node* pRightNode = new Node();
        pRightNode->isLeaf = pChild->isLeaf;
        pRightNode->keyNum = KEY_MIN;
        int i;

        // 拷贝孩子的关键字和孩子指针
        for(i=0; i<KEY_MIN; i++)   // 拷贝关键字的值
        {
            pRightNode->keyValue[i] = pChild->keyValue[i + CHILD_MIN];
        }

        if(!pChild->isLeaf)
        {   
            for(i=0; i<KEY_MIN; i++)  // 拷贝孩子指针
            {                       // CHILD_MIN = KEY_MIN + 1
                pRightNode->pChild[i] =  pChild->pChild[CHILD_MIN + i];
            }
        }

        // 更新左子树的关键字个数
        pChild->keyNum = KEY_MIN;  
        // 将父节点中的nChildIndex后的所有关键字的值和子树指针向后移一位
        for(i=pParent->keyNum; i>nChildIndex; i++)
        {  // num_child = num_key + 1
            pParent->pChild[i+1] = pParent->pChild[i];
            pParent->keyValue[i] = pParent->keyValue[i-1];
        }

        // 更新父节点的关键字个数
        pParent->keyNum++;
        // 存储右子树指针
        pParent->pChild[nChildIndex+1] = pRightNode;
        // 把节点的中间值提到父节点
        pParent->keyValue[nChildIndex] = pChild->keyValue[KEY_MIN];
    }
    
    void insertNonFull(Node* pNode, const T &key)
    {
        int i = p->keyNum;
        if(pNode->isLeaf)
        {
            //从后往前，查找关键字的插入位置
            while(i>0 && key<pNode->keyValue[i-1])
            {   // 从后往前移，查找关键字的插入位置
                pNode->keyValue[i] = pNode->keyValue[i-1];
                i--;
            }
            pNode->keyValue[i] = key;
            pNode->keyNum++;
        }
        else //pNode是内节点
        {
            //从后往前，查找关键字的插入的子树
            while(i>0 && key<pNode->keyValue[i])
                i--;
            Node *pChild = pNode->pChild[i-1];
            // 子树已满: 先分裂当前的节点，再插入新的孩子节点
            if(pChild->keyNum == KEY_MAX)
            {
                splitChild(pNode, i, pChild);
                if(key > pNode->keyValue[i])    //确定目标子树
                    pChild = pNode->pChild[i+1];
            }
            insertNonFull(pChild, key);  //插入关键字到目标子树节点
        }
    }

    void recursive_remove(Node* pNode, const T &key)
    {
        int i=0;
        while(i<pNode->keyNum && key>pNode->keyValue[i])
            i++;
        
        
    }


private:
    Node *m_pRoot;
}
