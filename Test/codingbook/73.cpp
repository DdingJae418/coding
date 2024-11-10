#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 0; dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1] % 1234567) + (dp[i-2] % 1234567);
    }
    int answer = dp[n] % 1234567;

    return answer;
}