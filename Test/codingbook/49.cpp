#include <string>
#include <vector>

using namespace std;

int maxDepth = 0;
vector<vector<int>> dg;
vector<bool> visited(8, false);

void exploreDungeon(int depth, int k)
{
    // 깊이 갱신
    if(maxDepth < depth) maxDepth = depth;

    // 각 던전 탐험
    for (int i = 0; i < dg.size(); i++)
    {
        if(visited[i] || dg[i][0] > k)
            continue;

        visited[i] = true;
        exploreDungeon(depth + 1, k - dg[i][1]);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dg = dungeons;

    exploreDungeon(0, k);

    return maxDepth;
}