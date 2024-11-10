#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> lion(11, 0);
vector<int> answer;
int maxDiff = -1;

int checkScore(const vector<int> apeach, const vector<int> lion)
{
    int ascore = 0, lscore = 0;
    for (int i = 0; i < apeach.size(); i++)
    {
        if(apeach[i] == 0 && lion[i] == 0)
        {
            continue;
        }
        else if(apeach[i] >= lion[i])
        {
            ascore += 10 - i;
        }
        else
        {
            lscore += 10 - i;
        }
    }

    return lscore - ascore;
}

void dfs(const vector<int> apeach, int score, int arrow)
{
    if(score == -1 || arrow == 0)
    {
        lion[10] = arrow;
        int diff = checkScore(apeach, lion);
        if(diff > 0 && diff > maxDiff)
        {
            maxDiff = diff;
            answer = lion;
        }
        lion[10] = 0;
        return;
    }

    if(arrow > apeach[score])
    {
        lion[score] = apeach[score] + 1;
        dfs(apeach, score - 1, arrow - lion[score]);
        lion[score] = 0;
    }

    dfs(apeach, score -1, arrow);

    return;
}

vector<int> solution(int n, vector<int> info) {
    
    dfs(info, 10, n);

    if (maxDiff == -1) return vector<int>(1, -1);
    else return answer;
}