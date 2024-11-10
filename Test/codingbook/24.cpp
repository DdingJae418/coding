#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string GetUserId(const string &record)
{
    string id;
    int flag = 0;

    for (char c : record)
    {
        if(c == ' ') flag++;
        if(flag > 1)
            break;
        else if(flag > 0)
            id += c;
    }

    return id.substr(1);
}

string GetNickName(const string &record)
{
    string nickName;
    int flag = 0;

    for (char c : record)
    {
        if(c == ' ') flag++;
        if(flag > 1)
            nickName += c;
    }

    return nickName.substr(1);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> userNickname;

    // record 돌면서 유저 최종 닉네임 확인
    for (int i = 0; i < record.size(); i++)
    {
        // 유저 퇴장을 제외하고
        if(record[i].front() != 'L')
        {
            userNickname[GetUserId(record[i])] = GetNickName(record[i]);
        }
    }

    // 닉네임에 따라 관리자 로그 저장
    for (int i = 0; i < record.size(); i++)
    {
        // 유저 입장 시
        if(record[i].front() == 'E')
        {
            string log = userNickname[GetUserId(record[i])] + "님이 들어왔습니다.";
            answer.push_back(log);
        }
        // 유저 퇴장 시
        else if(record[i].front() == 'L')
        {
            string log = userNickname[GetUserId(record[i])] + "님이 나갔습니다.";
            answer.push_back(log);
        }
    }

    return answer;
}