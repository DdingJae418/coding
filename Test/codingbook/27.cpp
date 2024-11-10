#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second > p2.second;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    map<int, map<string, int>> courseMap;

    // 각 orders 에서 나올 수 있는 모든 코스 조합 찾기
    for (string &order : orders)
    {
        map<int, set<string>> courseSet;
        sort(order.begin(), order.end());
        while(next_permutation(order.begin(), order.end()))
        {
            // 각 course마다 찾기
            for (int c : course) 
            {
                if(order.length() < c) continue;
                string s = order.substr(0, c);
                sort(s.begin(), s.end());
                courseSet[c].insert(s);
            }
        }

        // 각 조합의 등장 횟수 1씩 증가
        for (int c : course)
        {
            for (string s : courseSet[c])
                courseMap[c][s]++;
        }
    }

    // 등장 횟수 가장 높은 조합 선별
    for (int c : course)
    {
        if(courseMap[c].empty()) continue;
        vector<pair<string, int>> tempVec(courseMap[c].begin(), courseMap[c].end());
        sort(tempVec.begin(), tempVec.end(), compare);
        int max = tempVec[0].second;
        if(max < 2) continue;
        for(const pair<string, int> &p : courseMap[c])
        {
            if(p.second==max)
                answer.push_back(p.first);
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
}