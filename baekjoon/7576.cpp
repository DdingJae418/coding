#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m,n;

bool CheckBoundary(int row, int col)
{
    return row >=0 && row < n && col >= 0 && col < m;
}

struct Node
{
    int row, col, day;
    Node(int row, int col, int day) : row(row), col(col), day(day) {}
};

int main(void)
{
    cin>>m>>n;

    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<Node> q;

    int answer = 0;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin>>val;
            graph[i][j] = val;
            if (val != 0) visited[i][j] = true; 
            if (val == 1) q.emplace(i, j, 0);
        }
    }

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        answer = max(answer, cur.day);

        for (int i = 0; i < 4; i++)
        {
            int nrow = cur.row + dy[i];
            int ncol = cur.col + dx[i];

            if (CheckBoundary(nrow, ncol) && !visited[nrow][ncol])
            {
                visited[nrow][ncol] = true;
                q.emplace(nrow, ncol, cur.day + 1);
            }

        }
    }

    for (auto visit : visited)
        if (count(visit.begin(), visit.end(), false) > 0)
        {
                cout<<(-1)<<endl;
                return 0;
        }

    cout<<answer<<endl;

    return 0;
}