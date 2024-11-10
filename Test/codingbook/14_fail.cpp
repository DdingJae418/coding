#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> trashCan;
    bool * arr = new bool[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = true;
    }
    int currentLine = k;
    string answer = "";

    for(int i = 0; i < cmd.size(); i++)
    {
        if(cmd[i][0] == 'U')
        {
            int x = stoi(cmd[i].substr(2));
            for (int j = 0; j < x; j++)
            {
                do
                {
                    currentLine--;
                } while (!arr[currentLine]);
            }
        } 
        else if(cmd[i][0] == 'D')
        {
            int x = stoi(cmd[i].substr(2));
            for (int j = 0; j < x; j++)
            {
                do
                {
                    currentLine++;
                } while (!arr[currentLine]);
            }
        } 
        else if(cmd[i][0] == 'C')
        {
            trashCan.push(currentLine);
            arr[currentLine] = false;
            int temp = currentLine;
            do
            {
                currentLine++;
                if(currentLine == n) break;
            } while (!arr[currentLine]);
            if(currentLine == n)
            {
                do
                {
                    temp--;
                } while (!arr[temp]);
                currentLine = temp;
            }
        } 
        else
        {
            arr[trashCan.top()] = true;
            trashCan.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i])
            answer+='O';
        else
            answer+='X';
    }

    delete[] arr;

    return answer;
}

int main(void)
{
    solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"});
}