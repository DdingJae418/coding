#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
private:
    vector<int> parents, rank;

public:
    DisjointSet(int size) : parents(size, -1), rank(size, 0) {}

    int find(int x)
    {
        if (parents[x] == -1)
            return x;

        return parents[x] = find(parents[x]);
    }

    void merge(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x != root_y)
        {
            if (rank[root_x] < rank[root_y])
            {
                parents[root_x] = root_y;
            }
            else if (rank[root_y] < rank[root_x])
            {
                parents[root_y] = root_x;
            }
            else
            {
                parents[root_y] = root_x;
                rank[root_x]++;
            }
        }
    }

    bool isCycle(int x, int y)
    {
        return find(x) == find(y);
    }
};


int solution(int n, vector<vector<int>> costs)
{
    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) { return a[2] < b[2]; });

    DisjointSet dSet(n);
    int totalCosts = 0;

    for (const auto& cost : costs)
    {
        if (false == dSet.isCycle(cost[0], cost[1]))
        {
            dSet.merge(cost[0], cost[1]);
            totalCosts += cost[2];
        }
    }

    return totalCosts;
}