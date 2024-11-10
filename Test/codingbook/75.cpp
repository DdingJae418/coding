#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    vector<vector<int>> dp = triangle;

    for (int i = 1; i < height; i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][0] + dp[i][j];
            }
            else if(j == dp[i].size() - 1)
            {
                dp[i][j] = dp[i-1][j-1] + dp[i][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + dp[i][j];
            }
        }
    }

    return *max_element(dp[height-1].begin(), dp[height-1].end());
}