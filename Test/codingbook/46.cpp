#include <string>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited, int &nodeNum)
{
    nodeNum++;
    visited[start] = true;

    for (int neighbor : graph[start])
    {
        if(!visited[neighbor])
            dfs(neighbor, graph, visited, nodeNum);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;

    // wires에서 하나씩 뺴고 그래프 생성
    for (int i = 0; i < wires.size(); i++)
    {
        // 그래프 생성
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for(int j = 0; j < wires.size(); j++)
        {
            if(j == i) continue;
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }

        // 각 n에 대하여 그래프 탐색
        vector<int> nums;
        for (int j = 1 ; j <= n; j++)
        {
            if(!visited[j])
            {
                int num = 0;
                dfs(j, graph, visited, num);
                nums.push_back(num);
            }
        }
        
        int diff = nums[0] > nums[1] ? nums[0] - nums[1] : nums[1] - nums[0];
        if(answer == -1) answer = diff;
        else answer = min(answer, diff);
    }

    return answer;
}