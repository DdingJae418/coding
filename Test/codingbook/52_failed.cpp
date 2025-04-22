#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> weakPoints;
vector<bool> visited;
vector<int> workerDist;
vector<bool> used;
int circleSize;
int answer = kInfinite;

void dfs(int weakPoint, int workerCnt)
{
    // 취약 지점을 다 돌았을 경우
    if(weakPoint == weakPoints.size())
    {
        // 모든 취약 지점 들렀는지 확인
        for (bool v : visited)
            if(!v) return;
        
        // 갱신
        answer = min(answer, workerCnt);
        return;
    }

    // 해당 지점 이미 지났을 경우
    if(visited[weakPoint]) 
    {
        dfs(weakPoint + 1, workerCnt);
        return;
    }

    // 취약 지점에 한 명씩 보내기
    for (int i = 0; i < workerDist.size(); i++)
    {
        if(used[i]) continue;

        // 커버 범위 방문
        int cover = weakPoints[weakPoint] + workerDist[i];
        for (int j = weakPoint; j < weakPoints.size(); j++)
        {
            if(weakPoints[j] <= cover) visited[j] = true;
        }
        if(cover >= circleSize)
        {
            for (int j = 0; j < weakPoint; j++)
            {
                if(weakPoints[j] <= cover - circleSize) visited[j] = true;
            }
        }
        used[i] = true;

        dfs(weakPoint + 1, workerCnt + 1);

        // 커버 범위 방문 취소
        for (int j = weakPoint; j < weakPoints.size(); j++)
        {
            if(weakPoints[j] <= cover) visited[j] = false;
        }
        if(cover >= circleSize)
        {
            for (int j = 0; j < weakPoint; j++)
            {
                if(weakPoints[j] <= cover - circleSize) visited[j] = false;
            }
        }
        used[i] = false;
    }

    // 해당 취약 지점에 안 보내기
    dfs(weakPoint + 1, workerCnt);
}

int solution(int n, vector<int> weak, vector<int> dist) {
    weakPoints = weak;
    visited.resize(weakPoints.size(), false);
    workerDist = dist;
    used.resize(dist.size(), false);
    circleSize = n;

    // 몇 번째 취약 지점 보낼지 결정
    dfs(0, 0);

    if(answer = kInfinite) return -1;
    else
        return answer;
}