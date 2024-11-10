#include <vector>

using namespace std;

vector<vector<int>> board;
const int SIZE = 9;

bool check(int x, int y, int val)
{
    for (int i = 0; i < SIZE; i++)
    {
        if(board[y][i] == val || board[i][x] == val)
            return false;
        if(board[(y/3)*3 + i/3][(x/3)*3 + i%3] == val)
            return false;
    }
    return true;
}

pair<int, int> getNextSlot(int x, int y)
{
    if(x + 1 == SIZE) 
        return {0, y + 1};
    else 
        return {x + 1, y};
}

bool writeSlot(int x, int y)
{   
    // 스도쿠를 다 채웠음
    if(y == SIZE) 
        return true;

    // 이미 채워져 있다면 다음 슬롯으로 이동
    else if(board[y][x] != 0)
    {
        auto next = getNextSlot(x,y);
        return writeSlot(next.first, next.second);
    }
    
    // 해당 슬롯을 채움
    else
    {
        // 1~9 시도
        for (int i = 1; i <= SIZE; i++)
        {
            if(check(x, y, i))
            {
                board[y][x] = i;
                auto next = getNextSlot(x, y);
                if(writeSlot(next.first, next.second))
                    return true;
                board[y][x] = 0;
            }
        }

        // 안 됐음
        return false;
    }
}

vector<vector<int>> solution(vector<vector<int>> input_board)
{
    board = input_board;

    writeSlot(0,0);

    return board;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<vector<int>> vec)
{
    
  for(int i = 0; i < vec.size(); i++ ){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
    
}

int main()
{
  print(solution({
                    {5, 3, 0, 0, 7, 0, 0, 0, 0},
                    {6, 0, 0, 1, 9, 5, 0, 0, 0},
                    {0, 9, 8, 0, 0, 0, 0, 6, 0},
                    {8, 0, 0, 0, 6, 0, 0, 0, 3},
                    {4, 0, 0, 8, 0, 3, 0, 0, 1},
                    {7, 0, 0, 0, 2, 0, 0, 0, 6},
                    {0, 6, 0, 0, 0, 0, 2, 8, 0},
                    {0, 0, 0, 4, 1, 9, 0, 0, 5},
                    {0, 0, 0, 0, 8, 0, 0, 7, 9}
                }));

  /*
    출력값
    5 3 4 6 7 8 9 1 2 
    6 7 2 1 9 5 3 4 8 
    1 9 8 3 4 2 5 6 7 
    8 5 9 7 6 1 4 2 3 
    4 2 6 8 5 3 7 9 1 
    7 1 3 9 2 4 8 5 6 
    9 6 1 5 3 7 2 8 4 
    2 8 7 4 1 9 6 3 5 
    3 4 5 2 8 6 1 7 9 
  */
  print(solution({
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0}
                }));
                
  /*
    출력값
        1 2 3 4 5 6 7 8 9 
        4 5 6 7 8 9 1 2 3 
        7 8 9 1 2 3 4 5 6 
        2 1 4 3 6 5 8 9 7 
        3 6 5 8 9 7 2 1 4 
        8 9 7 2 1 4 3 6 5 
        5 3 1 6 4 2 9 7 8 
        6 4 2 9 7 8 5 3 1 
        9 7 8 5 3 1 6 4 2 
  */
  return 0;
}