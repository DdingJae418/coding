#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++)  
        dp[0][i] = board[0][i];
    for (int i = 0; i < row; i++)  
        dp[i][0] = board[i][0];
    

    for(int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if(board[i][j] == 1)
            {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
    }

    int maxNum = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            maxNum = max(maxNum, dp[i][j]);

    return maxNum * maxNum;
}