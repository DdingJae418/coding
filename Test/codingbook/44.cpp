#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<int>> graph(N, vector<int>(N, INT_MAX));
    vector<bool> visited(N, false);
    vector<int> distances(N, INT_MAX);

    // 그래프 생성
    for (int i = 0; i < road.size(); i++)
    {
        if(road[i][2] < graph[road[i][0] - 1][road[i][1] - 1])
        {
            graph[road[i][0] - 1][road[i][1] - 1] = road[i][2];
            graph[road[i][1] - 1][road[i][0] - 1] = road[i][2];
        }
    }

    // 다익스트라
    distances[0] = 0;
    for (int i = 0; i < N; i++)
    {
        int minDist = INT_MAX;
        int current = -1;

        for (int j = 0; j < distances.size(); j++)
        {
            if(!visited[j] && minDist > distances[j])
            {
                current = j;
                minDist = distances[j];
            }
        }

        visited[current] = true;

        for (int j = 0; j < N; j++)
        {
            if(graph[current][j] != INT_MAX && !visited[j])
            {
                if(distances[j] > distances[current] + graph[current][j])
                    distances[j] = distances[current] + graph[current][j];
            }
        }
    }

    // K 이하 마을 개수 
    for (int dist : distances)
    {
        if (dist <= K) answer++;
    }

    return answer;
}