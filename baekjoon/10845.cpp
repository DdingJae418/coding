#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    int num = 0;
    cin>>num;
    
    queue<int> q;
    while (num--)
    {
        string command;
        cin>>command;

        if ("push" == command)
        {
            int n = 0;
            cin>>n;
            q.push(n);
        }
        else if ("pop" == command)
        {
            if (q.empty())
            {
                cout<<(-1)<<' ';
            }
            else
            {
                cout<<q.front()<<' ';
                q.pop();
            }
        }
        else if ("size" == command)
        {
            cout<<q.size()<<' ';
        }
        else if ("empty" == command)
        {
            cout<<(q.empty() ? 1 : 0)<<' ';
        }
        else if ("front" == command)
        {
            cout<<(q.empty() ? -1 : q.front())<<' ';
        }
        else if ("back" == command)
        {
            cout<<(q.empty() ? -1 : q.back())<<' ';
        }
    }

    return 0;
}