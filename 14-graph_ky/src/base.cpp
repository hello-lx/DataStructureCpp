#include "base.h"



Graph::Graph(){
    int n = LENGTH(chars);
    ch2int = new map<char, int>();
    int2ch = new map<int, char>();
    
    for(int i=0; i<n; i++){
            ch2int->insert(pair<char, int>(chars[i], i));
            int2ch->insert(pair<int, char>(i, chars[i]));
    }
}

Graph::~Graph(){
    if(ch2int)
        delete ch2int;
    
    if(int2ch)
        delete int2ch;
}


void Graph::createGraphMatrx(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori,
                                 vector<vector<int>> &matrix){
    /**
     *   @letters: {{'A', 'B'}, {'B', 'C'}, ...}
     *   @weights: {   1,          2,       ...}
     *   @ori: 创建的图是否为有向图
     */

    // 初始化
    map<char, int>::iterator it1, it2;
    for(int i=0; i<letters.size(); i++)
    {   
        it1 = ch2int->find(letters[i][0]), it2 = ch2int->find(letters[i][1]);
        
        matrix[it1->second][it2->second] = weights[i];

        if (ori)
            matrix[it2->second][it1->second] = weights[i];
    }
}

void Graph::printMatrix(const vector<vector<int>> &matrix){
    for(int i=0; i < matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

void Graph::testMatrix(){
    vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4};
    bool ori = true;
    
    int nVertexs = 6;
    // cout << sizeof(vertexs) << ' ' << sizeof(int) << ' ' << nVertexs << endl;
    vector<vector<int>> matrix(nVertexs, vector<int>(nVertexs, 0));
    createGraphMatrx(arcs, weights, ori, matrix);
    printMatrix(matrix);
}


void Graph::createGraphTable(const vector<vector<char>> &letters, const vector<int> &weights, const bool &ori, vector<GTNode*> &table){
    map<char, int>* heads = new map<char, int>();  // 用于判断是否需要重新创建表头
    map<char, int>::iterator it;
    int headId=0;

    for(int i; i<letters.size(); i++)
    {   
        it = heads->find(letters[i][0]);

        if(it == heads->end())
        {
            GTNode* n2 = new GTNode(letters[i][1], 0, nullptr);
            GTNode* n1 = new GTNode(letters[i][0], weights[i], n2);
            heads->insert(pair<char, int>(letters[i][0], headId++));
            table.push_back(n1);
        }
        else
        {
            GTNode* head = table[it->second];
            while(head->next)
                head = head->next;
            head->next = new GTNode(letters[i][1], 0, nullptr);
            head->weight = weights[i];
        }
        cout << table.size() << endl;
    }

    // for(int i=0; i<table.size(); i++){
    //     GTNode* n = table[i];
    //     cout << n->name;
    //     while(n->next){
    //         cout << " =" << n->weight << "=> " << n->next->name;
    //         n = n->next;
    //     }
    //     cout << endl;
    // }
}

void Graph::printTable(const vector<GTNode*> &table)
{
    for(int i=0; i<table.size(); i++){
        GTNode* n = table[i];
        cout << n->name;
        while(n->next){
            cout << " =" << n->weight << "=> " << n->next->name;
            n = n->next;
        }
        cout << endl;
    }
}

void Graph::testTable()
{
    vector<char> vertexs = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<vector<char>> arcs = {{'A', 'B'}, {'A', 'C'}, {'B', 'F'}, {'C', 'D'}, {'D', 'E'}};
    vector<int> weights = {1, 3, 5, 2, 4};
    bool ori = true;

    vector<GTNode*> table;
    createGraphTable(arcs, weights, ori, table);
    cout << table.size() << endl;   // bug: empty table
    printTable(table);
}
