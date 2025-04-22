#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int num = 0;
    cin>>num;

    vector<pair<int, int>> vec(num);
    for (int i = 0; i < num; i++)
    {
        cin>>vec[i].first>>vec[i].second;
    }

    sort(vec.begin(), vec.end());

    for (const auto& p : vec)
    {
        cout<<p.first<<' '<<p.second<<'\n';
    }

    return 0;
}