#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int num = 0;
    cin>>num;

    vector<pair<int, string>> vec(num);
    for (int i = 0; i < num; i++)
    {
        cin>>vec[i].first>>vec[i].second;
    }

    stable_sort(vec.begin(), vec.end(), [](const auto& a, const auto& b){ return a.first < b.first; });

    for (const auto& v : vec)
    {
        cout<<v.first<<' '<<v.second<<'\n';
    }

    return 0;
}