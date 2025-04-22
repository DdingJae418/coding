#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int boardSize;


bool check(int x, int y)
{
    if (x < 0 || x >= boardSize || y < 0 || y >= boardSize)
        return false;
    else return true;
}

struct Path
{
    int x, y, direction;
};

int solution(vector<vector<int>> board) {
    boardSize = board.size();
    int dist[boardSize][boardSize][4];
    memset(dist, -1, sizeof(dist));
    queue<Path> q;

    dist[0][0][3] = 0;
    dist[0][0][2] = 0;

    q.push({0,0,3});
    q.push({0,0,2});

    while(!q.empty())
    {
        Path p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if(check(nx, ny) && board[ny][nx] == 0)
            {
                int cost = p.direction == i ? dist[p.x][p.y][i] + 100 : dist[p.x][p.y][p.direction] + 600;
                 
                if(dist[nx][ny][i] == -1 || cost < dist[nx][ny][i])
                {
                    dist[nx][ny][i] = cost;
                    q.push({nx, ny, i});
                }
            }
        }
    }
    
    int minCost = kInfinite;
    for (int i = 0; i < 4; i++)
    {
        if(dist[boardSize - 1][boardSize - 1][i] == -1) continue;
        minCost = min(minCost, dist[boardSize - 1][boardSize - 1][i]);
    }

    return minCost;
}