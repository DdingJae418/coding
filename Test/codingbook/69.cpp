#include <string>
#include <vector>

using namespace std;

int width;
int height;

bool check(int x, int y)
{
    if(x < 0 || x >= width || y < 0 || y >= height)
        return false;
    else return true;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    width = board[0];
    height = board[1];
    int curx = width/2;
    int cury = height/2;

    for (string s : keyinput)
    {
        int nx, ny;
        if(s == "up")
        {
            nx = curx;
            ny = cury + 1;
        }
        else if(s == "down")
        {
            nx = curx;
            ny = cury - 1;
        }
        else if(s == "left")
        {
            nx = curx - 1;
            ny = cury;
        }
        else
        {
            nx = curx + 1;
            ny = cury;
        }
        if (check(nx, ny))
        {
            curx = nx;
            cury = ny;
        }
    }

    answer.push_back(curx - width/2);
    answer.push_back(cury - height/2);

    return answer;
}