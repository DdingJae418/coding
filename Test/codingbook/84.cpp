#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int, int> m;

    // 맵에 담기
    for (int i = 0; i < tangerine.size(); i++)
    {
        m[tangerine[i]]++;
    }

    // 백터로 옮기고 정렬
    vector<pair<int, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    // k개 뽑을 때 크기 종류 개수 확인
    for (int i = 0; i < v.size(); i++)
    {
        k -= v[i].second;
        answer++;

        if(k <= 0) break;
    }

    return answer;
}