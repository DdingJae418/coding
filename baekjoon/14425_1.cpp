#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    int n, m;
    int nums = 0;
    set<string> strs;

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        strs.insert(s);
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        if(strs.find(s) != strs.end()) 
            nums++;
    }

    cout<<nums;

    return 0;
}