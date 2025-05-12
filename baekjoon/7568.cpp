#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;

    vector<pair<int, int>> vec(N);
    vector<int> result(N);
    for (int i = 0; i < N; i++)
    {
        cin>>vec[i].first>>vec[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == j) continue;

            if (vec[j].first > vec[i].first && vec[j].second > vec[i].second)
                result[i]++;
        }
    }

    for (int i : result)
        cout<<i+1<<' ';

    return 0;
}