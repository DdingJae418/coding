#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    vector<int> dist;

    // 왼쪽과 첫번째 기지국 사이 거리
    if (stations[0] - w - 1 > 0)
        dist.push_back(stations[0] - w - 1);

    // 미리 설치된 각 기지국 사이의 거리 구하기
    for (int i = 0; i < stations.size() -1; i++)
    {  
        if(stations[i+1] - stations[i] > 2*w + 1)
        {
            dist.push_back(stations[i+1] - stations[i] - 2*w - 1);
        }
    }
    
    // 마지막 기지국과 오른쪽 사이 거리
    if (stations[stations.size() -1] + w < n)
        dist.push_back(n - (stations[stations.size() -1] + w));


    // 각 거리에 들어가는 기지국 범위 구하고 더하기
    for(int d : dist)
    {
        answer += (int)ceil(((double)(d))/(2*w+1));
    }


    return answer;
}