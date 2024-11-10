#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<unordered_set<int>> g;
vector<bool> visited;
vector<unordered_set<int>> weaker;
vector<unordered_set<int>> stronger;

unordered_set<int> updateRanking(int idx, unordered_set<int> strongerSet)
{
    visited[idx] = true;
    
    // 강자 리스트 갱신
    for (int s : strongerSet)
        stronger[idx].insert(s);
    strongerSet.insert(idx);
    
    // 약자 리스트 갱신
    for (int loser : g[idx])
    {
        if(!visited[loser])
        {
            auto weakerSet = updateRanking(loser, strongerSet);
            weaker[idx].insert(weakerSet.begin(), weakerSet.end());
        }
    }
    
    unordered_set<int> temp(weaker[idx].begin(), weaker[idx].end());
    temp.insert(idx);
    return temp;
}

int solution(int n, vector<vector<int>> results) {
    
    g.resize(n+1);
    visited.resize(n+1);
    weaker.resize(n+1);
    stronger.resize(n+1);
    
    // 순위 계산
    for (auto result : results)
    {
        g[result[0]].insert(result[1]);
        fill(visited.begin(), visited.end(), false);
        
        updateRanking(result[0], stronger[result[0]]);
    }
    
    // 순위 확장된 선수 몇 명?
    int answer = 0;
    for (int  i = 1; i <=n; i++ )
        if(stronger[i].size() + weaker[i].size() == n - 1)
            answer++;
    
    return answer;
}