#include <string>
#include <vector>
#include <stack>

using namespace std;

void ChangeToStack(vector<stack<int>> &boardStack, const vector<vector<int>> board)
{
    for(int i = 0; i < boardStack.size(); i++)
    {
        for (int j = board.size() - 1; j >= 0; j--)
        {
            if(board[j][i] != 0)
                boardStack[i].push(board[j][i]);
            else
                break;
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<stack<int>> boardStack(board[0].size());
    stack<int> basket;
    int answer = 0;

    ChangeToStack(boardStack, board);

    for (int i = 0; i < moves.size(); i++)
    {
        if(boardStack[moves[i]-1].empty()) break;

        int pick = boardStack[moves[i]-1].top();
        boardStack[moves[i]-1].pop();

        if(basket.empty() || basket.top() != pick)
            basket.push(pick);
        else
        {
            basket.pop();
            answer+=2;
        }

    }
    return answer;
}