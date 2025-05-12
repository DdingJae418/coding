#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.second != b.second)
            return a.second < b.second;
        else 
            return a.first < b.first;
    }
};

int main(void)
{
    int N = 0;
    cin>>N;

    vector<pair<int, int>> vec(N);
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cin>>it->first>>it->second;
    }

    sort(vec.begin(), vec.end(), Compare());

    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout<<it->first<<' '<<it->second<<'\n';
    }

    return 0;
}