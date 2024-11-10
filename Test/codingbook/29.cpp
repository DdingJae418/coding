#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* leftNode;
    Node* rightNode;
public: 
    Node(int value) : value(value), leftNode(nullptr), rightNode(nullptr)
    {}
};

void InsertNode(Node* parent, Node* child)
{
    if(parent->value > child->value)
    {
        if(parent->leftNode == nullptr) parent->leftNode = child;
        else InsertNode(parent->leftNode, child);
    }
    else
    {
        if(parent->rightNode == nullptr) parent->rightNode = child;
        else InsertNode(parent->rightNode, child);
    }
}

bool SearchNode(Node* root, int num)
{
    if(root->value == num) return true;
    else if(root->value > num)
    {
        if(root->leftNode == nullptr) return false;
        else return SearchNode(root->leftNode, num);
    }
    else
    {
        if(root->rightNode == nullptr) return false;
        else return SearchNode(root->rightNode, num);
    }
}

vector<bool> solution(vector<int> lst, vector<int> search_lst)
{
    vector<Node*> nodeList;
    vector<bool> answer;
    for(int i = 0; i< lst.size(); i++)
    {
        nodeList.push_back(new Node(lst[i]));
    }
    
    for(int i = 1; i < nodeList.size(); i++)
    {
        InsertNode(nodeList[0], nodeList[i]);
    }

    for(int i = 0; i < search_lst.size(); i++)
    {
        answer.push_back(SearchNode(nodeList[0], search_lst[i]));
    }

    for(int i = 0; i< lst.size(); i++)
    {
        delete nodeList[i];
    }

    return answer;
}

int main(void)
{
    vector<bool> answer = solution({5,3,8,4,2,1,7,10}, {1,2,5,6});
    for (bool val : answer)
        cout<<val<<" ";

    return 0;
}