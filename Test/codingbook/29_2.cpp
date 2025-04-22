#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node* leftNode, *rightNode;
public:
    Node(int val) : val(val), leftNode(nullptr), rightNode(nullptr) {}
};

class BST
{
private:
    Node* root;
private:
    Node* insertNode(Node* node, int key)
    {
        if (!node)
            return new Node(key);

        if (node->val < key)
        {
            node->rightNode = insertNode(node->rightNode, key);
            return node;
        }
        else 
        {
            node->leftNode = insertNode(node->leftNode, key);
            return node;
        }
    }

    bool searchNode(Node* node, int key)
    {
        if (!node)
            return false;

        if (node->val == key)
            return true;

        if (node->val < key)
            return searchNode(node->rightNode, key);
        else
            return searchNode(node->leftNode, key);
    }
public:
    BST() : root(nullptr) {}
    
    void insertKey(int key)
    {
        root = insertNode(root, key);
    }

    bool searchKey(int key)
    {
        return searchNode(root, key);
    }
};

vector<bool> solution(vector<int> lst, vector<int> search_lst)
{
    BST bst;
    for (int i : lst)
        bst.insertKey(i);

    vector<bool> result;
    result.reserve(search_lst.size());
    for (int i : search_lst)
        result.push_back(bst.searchKey(i));

    return result;
}

int main(void)
{
    vector<bool> answer = solution({5,3,8,4,2,1,7,10}, {1,2,5,6});
    for (bool val : answer)
        cout<<val<<" ";

    return 0;
}