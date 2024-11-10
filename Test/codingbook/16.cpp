#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> leftDays;

    // check left days
    for (int i = 0; i < progresses.size(); i++)
    {
        int leftDay = ((100 - progresses[i]) + speeds[i] - 1) / speeds[i];
        leftDays.push(leftDay);
    }

    // check publish
    int publish = leftDays.front();
    int num = 0;
    while (!leftDays.empty())
    {
        if (leftDays.front() <= publish)
        {
            leftDays.pop();
            num++;
        }
        else
        {
            answer.push_back(num);
            num = 0;
            publish = leftDays.front();
        }
    }
    if(num > 0)
    {
        answer.push_back(num);
    }

    return answer;
}