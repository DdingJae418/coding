#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    // 구매 리스트 맵 생성
    unordered_map<string, int> buyList;
    for (int i = 0; i < want.size(); i++)
    {
        buyList[want[i]] = number[i];
    }

    // discount 처음부터 10개 씩 확인
    for (int i = 0; i < discount.size() - 9; i++)
    {
        unordered_map<string, int> tempList = buyList;
        for (int  j = i; j < i + 10; j++)
        {
            if ((tempList.find(discount[j]) != tempList.end()))
            {
                tempList[discount[j]]--;
                if(tempList[discount[j]]==0)
                    tempList.erase(discount[j]);
            }
        }

        // 구매 리스트가 비어있으면 answer + 1
        if(tempList.empty()) answer++;
    }

    return answer;
}