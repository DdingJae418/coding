#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;


    // 첫번째 집 들를 때
    vector<int> dp1(money.size(), 0);
    dp1[0] = money[0];
    dp1[1] = 0;
    dp1[2] = money[0] + money[2];

    // 첫번째 집 들르지 않을 때
    vector<int> dp2(money.size(), 0);
    dp2[0] = 0;
    dp2[1] = money[1];
    dp2[2] = money[2];

    for(int i = 3; i < money.size(); i++)
    {
        // 마지막 집 확인
        if(i == money.size() - 1)
        {
            dp2[i] = max(dp2[i-2], dp2[i-3]) + money[i];
            break;
        }

        dp1[i] = max(dp1[i-2], dp1[i-3]) + money[i];
        dp2[i] = max(dp2[i-2], dp2[i-3]) + money[i];
    }

    int len = money.size() -1;

    return max({dp1[len-1], dp1[len-2], dp2[len], dp2[len-1]});
}