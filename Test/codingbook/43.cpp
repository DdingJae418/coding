#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int answer = 0;
vector<bool> visited;
vector<vector<int>> tree;
vector<int> comp;

void dfs(vector<int> cur)
{
    int sheep = 0;
    int wolf = 0;

    for (int i = 0; i < cur.size(); i++)
    {
        if(comp[cur[i]] == 1) wolf++;
        else sheep++;
    }

    if(wolf >= sheep) return;

    answer = max(answer, sheep);

    for (int i = 0; i < cur.size(); i++)
    {
        for (int n : tree[cur[i]])
        {
            if(visited[n]) continue;

            cur.push_back(n);
            visited[n] = true;
            dfs(cur);
            cur.pop_back();
            visited[n] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    tree.resize(info.size());
    visited.resize(info.size(), false);
    comp = info;

    // 그래프 생성
    for (int i = 0; i < edges.size(); i++)
    {
        tree[edges[i][0]].push_back(edges[i][1]);
    }

    visited[0] = true;

    dfs({0});

    return answer;
}