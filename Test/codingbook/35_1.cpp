#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<int> parent;
vector<int> setRank;

int find(int x)
{
    if(x == parent[x])
        return x;

    parent[x] = find(parent[x]);

    return parent[x];
}

void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(setRank[xroot]>setRank[yroot])
    {
        parent[yroot] = xroot;
    }
    else if(setRank[xroot]<setRank[yroot])
    {
        parent[xroot] = yroot;
    }
    else
    {
        parent[xroot] = yroot;
        setRank[yroot]++;
    }
}

int solution(int n, vector<vector<int>> costs) {

    sort(costs.begin(), costs.end(), 
        [](const vector<int> &a, const vector<int> &b){return a[2] < b[2];});

    parent.resize(n);
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
    setRank = vector<int>(n, 0);
    int totalCost = 0;


    // 각 경로가 하나의 집합인지 확인
    for (auto& path : costs)
    {
        int node1 = path[0];
        int node2 = path[1];
        int cost = path[2];

        // 집합 생성
        if (find(node1) != find(node2))
        {
            Union(node1, node2);
            totalCost += cost;
        }
    }

    return totalCost;
}