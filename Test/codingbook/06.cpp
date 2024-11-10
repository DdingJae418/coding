#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, double>> getFailure(int N, vector<int> stages)
{
    vector<int> playingStages(N, 0);
    vector<int> reachedStages(N, 0);

    for (int i = 0; i < stages.size(); i++)
    {
        if(stages[i] != N + 1)
            playingStages[stages[i] - 1]++;
        for (int j = 0; j < stages[i]; j++)
        {
            reachedStages[j]++;
        }
    }

    vector<pair<int, double>> failures(N);

    for (int i = 0; i < N; i++)
    {
        failures[i].first = i + 1;
        if (reachedStages[i] == 0)
            failures[i].second = 0;
        else
            failures[i].second = playingStages[i] / (double)(reachedStages[i]); 
    }

    return failures;
}

bool compare(pair<int, double> f, pair<int, double> s)
{
    if(f.second == s.second)
        return f.first < s.first;
    else
        return f.second > s.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> failures = getFailure(N, stages);

    sort(failures.begin(), failures.end(), compare);

    for (pair<int, double> failure : failures)
        answer.push_back(failure.first);

    return answer;
}

int main(void)
{
    //vector<int> answer = solution(4, {4,4,4,4,4});
    vector<int> answer = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});

    for (int i : answer)
        cout<<i<<' ';
}