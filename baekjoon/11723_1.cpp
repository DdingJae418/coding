#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin>>M;

    unordered_set<int> s;

    while (M--)
    {
        string cmd;
        int x;
        cin>>cmd;

        if ("add" == cmd)
        {
            cin>>x;
            s.insert(x);
        }
        else if ("remove" == cmd)
        {
            cin>>x;
            s.erase(x);
        }
        else if ("check" == cmd)
        {
            cin>>x;
            cout<<(s.end() != s.find(x) ? 1 : 0)<<'\n';
        }
        else if ("toggle" == cmd)
        {
            cin>>x;
            if (s.end() == s.find(x))
            {
                s.insert(x);
            }
            else
            {
                s.erase(x);
            }
        }
        else if ("all" == cmd)
        {
            for (int i = 1; i <= 20; i++)
            {
                s.insert(i);
            }
        }
        else if ("empty" == cmd)
        {
            s.clear();
        }
    }

    return 0;
}