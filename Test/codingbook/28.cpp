#include <vector>
#include <string>
#include <iostream>

using namespace std;

void PreRotate(int index, const vector<int> &tree, string &answer)
{
    answer+=to_string(tree[index]);
    if((2 * index + 1) < tree.size()) PreRotate(2*index+1, tree, answer);
    if((2 * index + 2) < tree.size()) PreRotate(2*index+2, tree, answer);
}

void MiddleRotate(int index, const vector<int> &tree, string &answer)
{
    if((2 * index + 1) < tree.size()) MiddleRotate(2*index+1, tree, answer);
    answer+=to_string(tree[index]);
    if((2 * index + 2) < tree.size()) MiddleRotate(2*index+2, tree, answer);
}

void PostRotate(int index, const vector<int> &tree, string &answer)
{
    if((2 * index + 1) < tree.size()) PostRotate(2*index+1, tree, answer);
    if((2 * index + 2) < tree.size()) PostRotate(2*index+2, tree, answer);
    answer+=to_string(tree[index]);
}

vector<string> solution(vector<int> nodes)
{
    vector<string> answers(3);

    PreRotate(0, nodes, answers[0]);
    MiddleRotate(0, nodes, answers[1]);
    PostRotate(0, nodes, answers[2]);

    return answers;
}

int main(void)
{
    vector<string> answers = solution({1,2,3,4,5,6,7});
    for (string s : answers)
        cout<<s<<endl;
}