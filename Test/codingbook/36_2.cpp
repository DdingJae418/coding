#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<char, vector<char>> adjList;
    unordered_set<char> visited;

private:
    void dfs(char node, vector<char>& result)
    {
        visited.insert(node);
        result.push_back(node);

        for (auto neighbor : adjList[node])
        {
            if (visited.find(neighbor) == visited.end())
                dfs(neighbor, result);
        }
    }

public:
    void addEdge(char u, char v)
    {
        adjList[u].push_back(v);
    }

    vector<char> startDfs(char start)
    {
        visited.clear();

        vector<char> result;
        dfs(start, result);

        return result;
    }
};

vector<char> solution(vector<pair<char, char>> graph, char start)
{
    Graph g;

    for (const auto& edge : graph)
    {
        g.addEdge(edge.first, edge.second);
    }

    return g.startDfs(start);
}

int main(void)
{
    vector<char> answer = solution({{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}}, 'A');

    for (char a : answer)
        cout<<a<<' ';
    cout<<endl;
}