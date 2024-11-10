#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_set<int> visited;
vector<int> result;
queue<int> searchQueue;


void bfs()
{
    if(searchQueue.empty()) return;

    int nextNode = searchQueue.front();
    searchQueue.pop();

    for (int neighbor : adjList[nextNode])
    {
        if(visited.find(neighbor) == visited.end())
        {
            visited.insert(neighbor);
            searchQueue.push(neighbor);
            result.push_back(neighbor);
        }
    }

    bfs();
}


vector<int> solution(vector<pair<int, int>> graph, int start)
{
    for (auto edge : graph)
        adjList[edge.first].push_back(edge.second);

    visited.insert(start);
    result.push_back(start);
    searchQueue.push(start);

    bfs();
    
    return result;
}

void init()
{
    adjList.clear();
    result.clear();
    visited.clear();
}
void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution({{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}}, 1)); //출력값 : 1 2 3 4 5 6 7 8 9
    init();
    print(solution({{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}}, 1)); //출력값 : 1 2 3 4 5 0
    return 0;
}