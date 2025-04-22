#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator() (string a, string b)
    {
        if (a.length() == b.length())
            return a < b;
        else
            return a.length() < b.length();
    }
};

int main(void)
{
    int num = 0;
    cin>>num;

    vector<string> strs(num);

    while (num--)
    {
        cin>>strs[num];
    }

    sort(strs.begin(), strs.end(), Compare());
    strs.erase(unique(strs.begin(), strs.end()), strs.end());

    for (string s : strs)
    {
        cout<<s<<endl;
    }

    return 0;
}