#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    set<string> bannedList;
    unordered_map<string, int> banedNum;
    unordered_map<string, set<string>> requireList;

    for (const string& str : report)
    {
        stringstream ss(str);
        string user, banned;
        ss>>user>>banned;

        // 각 유저 신고 명단 설정
        if(requireList[user].find(banned) == requireList[user].end())
        {
            // 해당 유저 신고받은 횟수 추가
            banedNum[banned]++;

            // 명단에 추가
            requireList[user].insert(banned);

            // 밴 명단에 인원 추가
            if(banedNum[banned] >= k)
                bannedList.insert(banned);
        }
    }

    // 각 유저 신고 명단 검사 후 메일 횟수 결정
    for (const string &user : id_list)
    {
        int mailNum = 0;

        for (string reportUser : requireList[user])
        {
            if(bannedList.find(reportUser) != bannedList.end())
                mailNum++;
        }
        answer.push_back(mailNum);
    }


    return answer;
}