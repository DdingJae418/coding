#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, string> referralMap;
    map<string, int> moneyMap;

    // 구성원 트리 구성
    for (int i = 0; i < enroll.size(); i++)
    {
        if(referral[i] == "-") referralMap[enroll[i]] = "center";
        else referralMap[enroll[i]] = referral[i];
    }

    // 각 판매자의 수익을 배분
    for (int i = 0; i < seller.size(); i++)
    {
        int profit = amount[i] * 100;
        moneyMap[seller[i]] += (int)ceil(profit * 0.9f);
        string refed = seller[i];

        // 추천인에게 10% 수익 배분
        while(refed != "center")
        {
            string ref = referralMap[refed];
            profit = (int)floor(profit * 0.1f);
            if(profit == 0) break;
            moneyMap[ref] += (int)ceil(profit * 0.9f);
            refed = ref;
        }
        moneyMap["center"] += (int)floor(profit * 0.1f);
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(moneyMap[enroll[i]]);
    }

    return answer;
}