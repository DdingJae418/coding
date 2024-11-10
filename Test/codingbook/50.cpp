#include <string>
#include <vector>

using namespace std;

vector<vector<int>> chassBoard;
int boardSize;
int answer = 0;

bool check(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if(chassBoard[i][col] == 1) return false;
    }

    for (int i = 1; i <= row; i++)
    {
        if(col - i >= 0)
        {
            if(chassBoard[row-i][col-i] == 1)
                return false;
        }

        if(col + i < boardSize)
        {
            if (chassBoard[row-i][col+i] == 1)
                return false;
        }
    }

    return true;
}

void PutQueen(int row)
{
    // 모든 체스판을 채웠을 경우
    if(row == boardSize)
    {
        answer++;
        return;
    }

    // 행의 모든 열에 놓았을 경우
    for (int i = 0; i < boardSize; i++)
    {
        if(check(row, i))
        {
            chassBoard[row][i] = 1;
            PutQueen(row + 1);
            chassBoard[row][i] = 0;
        }
    }
}

int solution(int n) {
    chassBoard.resize(n, vector<int>(n, 0));
    boardSize = n;

    PutQueen(0);
    
    return answer;
}