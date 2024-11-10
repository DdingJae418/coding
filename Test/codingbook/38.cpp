#include <iostream>
#include <vector>
#include <climits>
#include <unordered_set>

using namespace std;

class Node
{
public:
    int number;
    int weight;
public: 
    Node(int n, int w) : number(n), weight(w) {}
};

vector<vector<Node>> graph;
unordered_set<int> visited;
vector<int> distances;
vector<int> parents;

void dijckstra(int node)
{
    // 노드 방문
    visited.insert(node);

    // 거리 갱신
    for (Node n : graph[node])
    {
        if(distances[n.number] > distances[node] + n.weight)
        {
            distances[n.number] = distances[node] + n.weight;
            parents[n.number] = node;
        }
    }

    // 거리가 제일 짧은 노드 선택
    int minDist = INT_MAX;
    int nextNode = -1;
    for (int i = 0; i < distances.size(); i++)
    {
        if (visited.find(i) != visited.end()) continue;
        
        if(distances[i] < minDist) 
        {
            nextNode = i;
            minDist = distances[i];
        }
    }

    if(nextNode == -1) return;
    else dijckstra(nextNode);
}

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
    // 그래프 초기화
    graph.clear();
    graph.resize(numNodes);
    distances.resize(numNodes);
    parents.resize(numNodes);
    visited.clear();
    for (int i = 0; i < numNodes; i++)
    {
        distances[i] = INT_MAX;
        parents[i]= -1;
    }
    for (auto& [from, to, weight] : edges)
    {
        graph[from].emplace_back(to, weight);
    }

    distances[start] = 0;
    parents[start] = start;

    dijckstra(start);

    return distances;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>


void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution(0, 3, {{0, 1, 9},{0, 2, 3},{1, 0, 5},{2, 1, 1}})); //출력값 : 0 4 3
    print(solution(0, 4, {{0, 1, 1}, {1, 2, 5}, {2, 3, 1}})); //출력값 : 0 1 6 7
    return 0;
}