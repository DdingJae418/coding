#include <vector>

using namespace std;

vector<vector<int>> dp;
string s1;
string s2;

int LCS(int i, int j)
{
    if(i == 0 || j == 0)
    {
        return 0;
    }
    else if(s1[i - 1] == s2[j - 1])
    {
        dp[i][j] = LCS(i-1, j-1) + 1;
        return dp[i][j];
    }
    else
    {
        dp[i][j] = max(LCS(i, j-1), LCS(i-1, j));
        return dp[i][j];
    }
}

int solution(string str1, string str2)
{
    int answer = 0;
    s1 = str1;
    s2 = str2;
    dp.resize(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    return LCS(str1.length(), str2.length());
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution("ABCBDAB","BDCAB") << endl; //출력값: 4
  cout << solution("AGGTAB", "GXTXAYB") << endl; //출력값 :4
  return 0;
}