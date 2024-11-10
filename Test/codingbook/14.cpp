#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> trashCan;
    vector<int> up(n);
    vector<int> down(n);
    string answer = "";
    for (int i = 0; i < n; i++)
    {
        up[i] = i-1;
        down[i] = i+1;
    }

    for (int i = 0; i < cmd.size(); i++)
    {
        if(cmd[i][0] == 'U')
        {
            int x = stoi(cmd[i].substr(2));
            for (int j = 0; j < x; j++)
            {
                k = up[k];
            }
        }
        else if(cmd[i][0] == 'D')
        {
            int x = stoi(cmd[i].substr(2));
            for (int j = 0; j < x; j++)
            {
                k = down[k];
            }
        }
        else if(cmd[i][0] == 'C')
        {
            trashCan.push(k);
            if(up[k] == -1)
            {
                up[down[k]] = -1;
                k = down[k];
            }
            else if(down[k] == n)
            {
                down[up[k]] = n;
                k = up[k];
            }
            else
            {
                up[down[k]] = up[k];
                down[up[k]] = down[k];
                k = down[k];
            }
        }
        else
        {
            int restore = trashCan.top();
            trashCan.pop();
            if(up[restore] == -1)
            {
                up[down[restore]] = restore;
            }
            else if(down[restore] == n)
            {
                down[up[restore]] = restore;
            }
            else
            {
                down[up[restore]] = restore;
                up[down[restore]] = restore;
            }
        }
    }

    answer.append(n, 'O');

    while(!trashCan.empty())
    {
        answer[trashCan.top()] = 'X';
        trashCan.pop();
    }

    return answer;
}