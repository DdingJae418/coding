#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Graph
{
private:
    unordered_map<int, vector<int>> adjList;
    unordered_set<int> visited;

public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    vector<int> bfs(int start)
    {
        visited.clear();
        vector<int> result;
        queue<int> q;

        q.push(start);
        result.push_back(start);
        visited.insert(start);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto neighbor : adjList[node])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    result.push_back(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        return result;
    }    
};

vector<int> solution(vector<pair<int, int>> graph, int start)
{
    Graph g;

    for (const auto& edge : graph)
    {
        g.addEdge(edge.first, edge.second);
    }

    return g.bfs(start);
}

void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //출력값 : 1 2 3 4 5 6 7 8 9
    print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //출력값 : 1 2 3 4 5 0
    return 0;
}