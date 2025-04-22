#include <vector>
#include <tuple>
#include <limits>

using namespace std;

const int kInfinite = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source)
{
    vector<vector<pair<int, int>>> graph(num_vertices);
    for (auto &[from, to, weight] : edges)
        graph[from].emplace_back(to, weight);
    
    vector<int> distances(num_vertices, kInfinite);
    distances[source] = 0;

    for (int i = 0; i < num_vertices - 1; i++)
    {
        for (int u = 0; u < num_vertices; u++)
        {
            for (const auto &[node, weight] : graph[u])
            {
                if(distances[node] > distances[u] + weight)
                    distances[node] = distances[u] + weight;
            }
        }
    }

    for (int u = 0; u < num_vertices; u++)
    {
        for (const auto &[node, weight] : graph[u])
        {
            if(distances[node] > distances[u] + weight)
                return vector<int>(1, -1);
        }
    }

    return distances;

}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;


void print(vector<int> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    print(solution(5, {{0, 1, 4}, {0, 2, 3}, {0, 4, -6}, {1, 3, 5}, {2, 1, 2}, {3, 0, 7}, {3, 2, 4},{4, 2, 2}}, 0)); //출력값 : 0 -2 -4 3 -6
    print(solution(4, {{0, 1, 5}, {0, 2, -1}, {1, 2, 2}, {2, 3,-2}, {3, 0, 2}, {3, 1, 6}}, 0)); //출력값 : -1

    return 0;
}