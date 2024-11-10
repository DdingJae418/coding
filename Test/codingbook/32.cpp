#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int id;
    int value;
    Node* left;
    Node* right;
public:
    Node(int id, int value) : id(id), value(value), left(nullptr), right(nullptr)
    {}
};

void Insert(Node* parent, Node* child)
{
    if(child->value < parent->value)
    {
        if(parent->left == nullptr) parent->left = child;
        else Insert(parent->left, child);
    }
    else
    {
        if(parent->right == nullptr) parent->right = child;
        else Insert(parent->right, child);
    }
}

void Preorder(Node* root, vector<int> &order)
{
    if(root == nullptr) return;

    order.push_back(root->id);
    Preorder(root->left, order);
    Preorder(root->right, order);
}

void Postorder(Node* root, vector<int> &order)
{
    if(root == nullptr) return;
     
    Postorder(root->left, order);
    Postorder(root->right, order);
    order.push_back(root->id);
}

bool compare(pair<int, vector<int>> node1, pair<int, vector<int>> node2)
{
    if(node1.second[1] == node2.second[1])
        return node1.second[0] < node2.second[0];
    else
        return node1.second[1] > node2.second[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int, vector<int>>> nodes;
    vector<Node*> nodeList;

    // 노드 담기
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        nodes.push_back(make_pair(i+1, nodeinfo[i]));
    }

    // 노드를 정렬
    sort(nodes.begin(), nodes.end(), compare);

    Node root(nodes[0].first, nodes[0].second[0]);

    // 이진트리 생성
    for (int i = 1; i < nodes.size(); i++)
    {
        Node* newNode = new Node(nodes[i].first, nodes[i].second[0]);
        nodeList.push_back(newNode);
        Insert(&root, newNode);
    }

    //전위 순회
    vector<int> pre;
    Preorder(&root, pre);
    answer.push_back(pre);

    //후위 순회
    vector<int> post;
    Postorder(&root, post);
    answer.push_back(post);

    for (Node* n : nodeList)
        delete n;

    return answer;
}