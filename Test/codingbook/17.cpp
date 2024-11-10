#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q1, q2, g;

    // make queue
    for (int i = 0; i < cards1.size(); i++)
        q1.push(cards1[i]);
    for (int i = 0; i < cards2.size(); i++)
        q2.push(cards2[i]);
    for (int i = 0; i < goal.size(); i++)
        g.push(goal[i]);

    // compare with goal string
    while (!g.empty())
    {
        if (q1.front() == g.front())
        {
            q1.pop(); g.pop();
        }
        else if (q2.front() == g.front())
        {
            q2.pop(); g.pop();
        }
        else
        {
            return "No";
        }

        if (g.empty()) return "Yes";

        if (q1.empty())
        {
            while(!g.empty() && (q2.front() == g.front()))
            {
                q2.pop(); g.pop();
            }
            if(g.empty()) return "Yes";
            else return "No";
        }
        if (q2.empty())
        {
            while(!g.empty() && (q1.front() == g.front()))
            {
                q1.pop(); g.pop();
            }
            if(g.empty()) return "Yes";
            else return "No";
        }
    }

    return answer;
}