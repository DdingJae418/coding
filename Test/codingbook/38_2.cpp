#include <iostream>
#include <limits>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        return a.second > b.second;
    }
};

class Graph
{
public:
    Graph(int nodeSize) : nodeSize_(nodeSize), adjList_(nodeSize) {}

    void addEdge(int start, int end, int weight)
    {
        adjList_[start].emplace_back(end, weight);
    }

    vector<int> dijkstra(int start)
    {
        vector<int> distance(nodeSize_, kInfinite);
        vector<bool> visited(nodeSize_, false);
        distance[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({start, 0});

        while (false == pq.empty())
        {
            int curNode = pq.top().first;
            int curDist = pq.top().second;
            pq.pop();

            if (true == visited[curNode])
                continue;

            visited[curNode] = true;

            for (const auto& [neighbor, weight] : adjList_[curNode])
            {
                int newDist = curDist + weight;
                if (newDist < distance[neighbor]) 
                {
                    distance[neighbor] = newDist;
                    pq.emplace(neighbor, newDist);
                }
            }
        }
        
        return distance;
    }
private:
    const int kInfinite = numeric_limits<int>::max();
    int nodeSize_;
    vector<vector<pair<int, int>>> adjList_;
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges)
{
    Graph g(numNodes);

    for (const auto& [start, end, weight] : edges)
    {
        g.addEdge(start, end, weight);
    }

    return g.dijkstra(start);
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