#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator() (const pair<int, int>& a, const pair <int, int>& b) const
    {
        return a.second > b.second;
    }
};

int main(void)
{
    int n = 0;
    cin>>n;
    vector<int> vec(n);
    vector<pair<int, int>> count(8001);
    for (int i = -4000; i <=4000; i++)
    {
        count[i + 4000].first = i;
    }

    for (int& v : vec)
    {
        cin>>v;
        count[v+4000].second++;
    }


    sort(vec.begin(), vec.end());
    sort(count.begin(), count.end(), Compare());

    int avg = round(accumulate(vec.begin(), vec.end(), 0.0) / n);
    int mid = vec[n / 2];
    int diff = *(vec.end()-1) - *vec.begin();

    vector<int> manyNums;
    int std = count.begin()->second;
    for (const auto& c : count)
    {
        if (c.second == std)
            manyNums.push_back(c.first);
        else
            break;
    }

    sort(manyNums.begin(), manyNums.end());

    int many = manyNums.size() > 1 ? *(manyNums.begin() + 1) : *manyNums.begin();

    cout<<avg<<'\n'<<mid<<'\n'<<many<<'\n'<<diff<<endl;

    return 0;
}