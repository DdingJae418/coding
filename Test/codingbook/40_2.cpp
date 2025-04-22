#include <vector>
#include <queue>

using namespace std;

struct Point
{
    int row, col, count;
};

class MazeMap
{
public:
    MazeMap(const vector<string>& maps) : width(maps[0].size()), height(maps.size()), maps(maps) { }

    int bfs(char start, char target)
    {
        bool visited[100][100] = {false};

        Point startPnt;
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (maps[i][j] == start)
                    startPnt = {i, j, 0};
            }
        }

        queue<Point> q;
        q.push(startPnt);
        visited[startPnt.row][startPnt.col] = true;

        while (false == q.empty())
        {
            Point curPnt = q.front();
            q.pop();

            if (maps[curPnt.row][curPnt.col] == target)
                return curPnt.count;

            for (int i = 0; i < 4; i++)
            {
                int nx = curPnt.col + dx[i];
                int ny = curPnt.row + dy[i];

                if (checkBorder(ny, nx) && !visited[ny][nx] && maps[ny][nx] != 'X')
                {
                    Point nextPnt = {ny, nx, curPnt.count + 1};
                    q.push(nextPnt);
                    visited[ny][nx] = true;
                }
            }
        }
        
        return -1;
    }

private:
    int width, height;
    vector<string> maps;
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

private:
    bool checkBorder(int row, int col)
    {
        return 0 <= row && row < height && 0 <= col && col < width;
    }
};

int solution(vector<string> maps)
{
    MazeMap m(maps);

    int distSToL = m.bfs('S', 'L');
    if (distSToL == -1)
        return -1;

    int distLtoE = m.bfs('L', 'E');

    return distLtoE == -1 ? -1 : distLtoE + distSToL;
}