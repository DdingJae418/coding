#include <vector>
#include <queue>
using namespace std;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

struct Point
{
    int x, y, count;
};

bool checkRange(int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    else return true;
}

int solution(vector<vector<int>> maps)
{
    n = maps.size();
    m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;

    q.push({0,0,1});
    visited[0][0] = true;

    while(!q.empty())
    {
        Point current = q.front();
        q.pop();

        if(current.x == m - 1 && current.y == n - 1) return current.count;

        for (int i = 0; i < 4; i++)
        {
            Point next = {current.x + dx[i], current.y + dy[i], current.count + 1};
            if(checkRange(next.x, next.y) && maps[next.y][next.x] == 1 && !visited[next.y][next.x])
            {
                q.push(next);
                visited[next.y][next.x] = true;
            }
        }
    }

    return -1;
}