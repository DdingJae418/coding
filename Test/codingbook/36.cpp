#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


map<char, vector<char>> adjList;
set<char> visited;

void dfs(char node, vector<char> &answer)
{
    if(visited.find(node) != visited.end()) return;

    answer.push_back(node);
    visited.insert(node);

    for (char n : adjList[node])
    {
        dfs(n, answer);
    }
}

vector<char> solution(vector<pair<char, char>> graph, char start)
{
    vector<char> answer;

    for (auto edge : graph)
        adjList[edge.first].push_back(edge.second);

    dfs(start, answer);

    return answer;
}

int main(void)
{
    vector<char> answer = solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A');

    for (char a : answer)
        cout<<a<<' ';
    cout<<endl;
}