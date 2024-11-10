#include <iostream>
#include <vector>

using namespace std;

vector<int> s(1000);
vector<int> setRank(1000, 0);

int Find(int x)
{
    int current = x;
    int parent = s[x];
    while(current != parent)
    {
        current = parent;
        parent = s[parent];
    }
    return current;
}

void Union(int x, int y)
{
    int xroot = Find(x);
    int yroot = Find(y);
    if(setRank[xroot] > setRank[yroot])
    {
        s[yroot] = xroot;
    }
    else if(setRank[xroot] < setRank[yroot])
    {
        s[xroot] = yroot;
    }
    else
    {
        s[yroot] = xroot;
        setRank[xroot]++;
    }
}

vector<bool> solution(int k, vector<vector<char>> operations)
{
    vector<bool> answer;


    for (int i = 0; i < s.size(); i++)
    {
        s[i] = i;
    }

    for (auto &operation : operations)
    {
        if(operation[0] == 'u')
        {
            Union(operation[1], operation[2]);
        }
        else
        {   
            answer.push_back(Find(operation[1]) == Find(operation[2])); 
        }
    }

    return answer;
}

int main(void)
{
    vector<bool> answer = solution(3, {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}});

    for (bool a : answer)
        cout<<a<<' ';
}