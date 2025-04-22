#include <string>
#include <vector>
#include <climits>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int width, height;
int answer = kInfinite;

vector<vector<bool>> visited;
vector<vector<int>> boardCopy;

bool check(int x, int y)
{
    if (x < 0 || x >= width || y < 0 || y >= height)
        return false;
    else return true;
}

void dfs(vector<pair<int, int>> cur)
{
    int corner = 0;
    int dir = 0;

    if(cur.back().first == width - 1 && cur.back().second == height - 1)
    {
        for (int i = 0; i < cur.size() - 1; i++)
        {
            int temp;
            if(cur[i].first == cur[i+1].first)
                temp = 1;
            else temp = -1;
            
            if(temp * dir == -1) corner++;
            
            dir = temp;
        }

        answer = min(answer, (int)(corner * 500 + (cur.size() - 1) * 100));
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> next = {cur.back().first + dx[i], cur.back().second + dy[i]};
            if(check(next.first, next.second) && boardCopy[next.second][next.first] == 0 && !visited[next.second][next.first])
            {
                visited[next.second][next.first] = true;
                cur.push_back(next);
                dfs(cur);
                cur.pop_back();
                visited[next.second][next.first] = false;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    width = board[0].size();
    height = board.size();
    visited.resize(height, vector<bool>(width, false));
    boardCopy = board;

    visited[0][0] = true;
    dfs({{0,0}});

    return answer;
}