#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    vector<int> dp(t.length(), INT_MAX);
    unordered_set<string> strDic(strs.begin(), strs.end());

    if(strDic.find(t.substr(0,1)) != strDic.end())
        dp[0] = 1;

    for (int i = 1; i < t.length(); i++)
    {
        for (int j = 0; j < min(i + 1, 5); j++)
        {
            if(j == i)
            {
                if(strDic.find(t.substr(i - j,j + 1)) != strDic.end())
                    dp[i] = 1;
            }
            else
            {
                if(dp[i-1-j] == INT_MAX) continue;

                if(strDic.find(t.substr(i - j,j + 1)) != strDic.end())
                    dp[i] = min(dp[i], dp[i-1-j] + 1);
            }
        }
    }

    if(dp[t.length()-1] == INT_MAX)
        return -1;
    else
        return dp[t.length()-1];
}