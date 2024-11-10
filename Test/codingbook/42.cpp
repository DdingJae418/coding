#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> disjointSet;
vector<int> rootRank;

int find(int node)
{
    if(disjointSet[node] == node) return node;

    return disjointSet[node] = find(disjointSet[node]);
}

void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if(rootRank[xroot] > rootRank[yroot])
    {
        disjointSet[yroot] = xroot;
    }
    else if (rootRank[xroot] < rootRank[yroot])
    {
        disjointSet[xroot] = yroot;
    }
    else
    {
        disjointSet[yroot] = xroot;
        rootRank[xroot]++;
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    set<int> roots;

    // 상호배타적 집합 초기화
    for (int i = 0; i < n; i++)
        disjointSet.push_back(i);
    rootRank.resize(n);

    // 상호배타적 집합 갱신
    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[0].size(); j++)
        {
            if(computers[i][j] == 1 && find(i) != find(j))
                Union(i, j);
        }
    }

    // 각 집합의 루트 노드 구하고 집합에 저장
    for (int i = 0; i < n; i++)
    {
        roots.insert(find(i));
    }

    // 집합 원소 개수 리턴
    return roots.size();
}