#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Pred(int left, int right)
{
    return 3 < right-left;
}

int main(void)
{
    vector<int> v;

    v.push_back(40);
    v.push_back(46);
    v.push_back(12);
    v.push_back(80);
    v.push_back(10);
    v.push_back(47);
    v.push_back(30);
    v.push_back(55);
    v.push_back(90);
    v.push_back(53);

    sort(v.begin(), v.end(), Pred);
    for (int i : v)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}