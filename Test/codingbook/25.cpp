#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genrePlaycount;
    map<int, string> rgenrePlaycount;

    vector<string> genresRank;

    // 각 장르 재생 횟수 파악
    for (int i = 0; i < genres.size(); i++)
    {
        genrePlaycount[genres[i]] += plays[i];
    }

    // 재생 횟수 순으로 장르 정렬
    for (pair p : genrePlaycount)
    {
        rgenrePlaycount[p.second] = p.first;
    }
    for (auto it = rgenrePlaycount.rbegin(); it != rgenrePlaycount.rend(); it++)
    {
        genresRank.push_back((*it).second);
    }

    // 장르별 곡 2개 선정
    for (string genre : genresRank)
    {
        int first = -1;
        int second = -1;
        for (int i = 0; i < genres.size(); i++)
        {
            // 장르 체크
            if(genres[i] != genre) continue;
            
            // 첫번째 값
            if(first == -1)
            {
                first = i;
                continue;
            }
            else if(second == -1)
            {
                // 값 비교
                if(plays[first] < plays[i])
                {
                    int temp = first;
                    first = i;
                    second = temp;
                }
                else
                {
                    second = i;
                }
                continue;
            }

            // 값 비교
            if(plays[first] < plays[i])
            {
                int temp = first;
                first = i;
                second = temp;
            }
            else if(plays[second] < plays[i])
            {
                second = i;
            }
        }

        answer.push_back(first);
        if (second != -1) answer.push_back(second);
    }


    return answer;
}