#include <vector>

using namespace std;

int solution(vector<vector<int>> arr)
{
    vector<vector<int>> dp(arr[0].size(), vector<int>(4, 0));
    int n =  arr[0].size()-1;

    for (int i = 0; i < arr[0].size(); i++)
    {
        if(i == 0)
        {
            dp[i][0] = arr[0][0];
            dp[i][1] = arr[1][0];
            dp[i][2] = arr[2][0];
            dp[i][3] = arr[0][0] + arr[2][0];
        }
        else
        {
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[0][i];
            dp[i][1] = max(max(dp[i-1][0], dp[i-1][2]), dp[i-1][3]) + arr[1][i];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + arr[2][i];
            dp[i][3] = dp[i-1][1] + arr[0][i] + arr[2][i];
        }
    }

    return max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3]));
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({{1, 3, 3, 2}, {2, 1, 4, 1}, {1, 5, 2, 3}}) << endl; //출력값 : 19
  cout << solution({{1, 7, 13, 2, 6}, {2, -4, 2, 5, 4}, {5, 3, 5, -3, 1}}) << endl; //출력값 : 32
  
  return 0;
}