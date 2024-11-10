#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>

using namespace std;

struct Compare
{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

int solution(vector<string> maps) {
    int answer = 0;
    int startNode;
    int endNode;
    int leverNode;
    
    // 2차원 맵 생성
    vector<vector<char>> vectorMap(maps.size());
    for (int i = 0; i < maps.size(); i++)
        for (char c : maps[i])
            vectorMap[i].push_back(c);

    // 인접 리스트 생성
    vector<vector<int>> adjList(maps.size() * maps[0].length());
    for (int i = 0; i < vectorMap.size(); i++)
    {
        for (int j = 0; j < vectorMap[i].size(); j++)
        {
            int nodeNum = i * vectorMap[i].size() + j;

            // 특이 노드인지 확인
            if (vectorMap[i][j] == 'S') startNode = nodeNum;
            else if (vectorMap[i][j] == 'E') endNode = nodeNum;
            else if (vectorMap[i][j] == 'L') leverNode = nodeNum;

            // 상
            if(i > 0)
                if(vectorMap[i-1][j] != 'X')
                    adjList[nodeNum].push_back((i - 1) * vectorMap[i].size() + j);
            // 하
            if(i < vectorMap.size() - 1)
                if(vectorMap[i+1][j] != 'X')
                    adjList[nodeNum].push_back((i + 1) * vectorMap[i].size() + j);
            // 좌
            if(j > 0)
                if(vectorMap[i][j-1] != 'X')
                    adjList[nodeNum].push_back(i * vectorMap[i].size() + j - 1);
            // 우
            if(j < vectorMap[i].size() - 1)
                if(vectorMap[i][j+1] != 'X')
                    adjList[nodeNum].push_back(i * vectorMap[i].size() + j + 1);
        }
    }

    if(adjList[startNode].size() == 0) return -1;


    // 출발 지점에서 래버까지 최단 거리 탐색
    vector<int> distances(adjList.size(), INT_MAX);
    distances[startNode] = 0;
    vector<bool> visited1(adjList.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq1;
    pq1.push({0, startNode});

    while(!pq1.empty())
    {
        int currentNode = pq1.top().second;
        int distance = pq1.top().first;
        pq1.pop();

        if (visited1[currentNode]) continue;

        visited1[currentNode] = true;

        for (int neighbor : adjList[currentNode])
        {
            if(distances[neighbor] > distance + 1)
            {
                distances[neighbor] = distance + 1;
                pq1.push({distance + 1, neighbor});
            }
        }
    }

    if (distances[leverNode] == INT_MAX) return -1;
    answer += distances[leverNode];

    // 레버에서 도착 지점까지 최단거리 탐색
    vector<int> distances1(adjList.size(), INT_MAX);
    distances1[leverNode] = 0;
    vector<bool> visited2(adjList.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq2;
    pq2.push({0, leverNode});

    while(!pq2.empty())
    {
        int currentNode = pq2.top().second;
        int distance = pq2.top().first;
        pq2.pop();

        if (visited2[currentNode]) continue;

        visited2[currentNode] = true;

        for (int neighbor : adjList[currentNode])
        {
            if(distances1[neighbor] > distance + 1)
            {
                distances1[neighbor] = distance + 1;
                pq2.push({distance + 1, neighbor});
            }
        }
    }

    if(distances1[endNode] == INT_MAX) return -1;
    answer += distances1[endNode];

    return answer;
}