#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int num = 0;
    cin>>num;
    
    stack<int> s;
    while (num--)
    {
        string command;
        cin>>command;

        if ("push" == command)
        {
            int n = 0;
            cin>>n;
            s.push(n);
        }
        else if ("pop" == command)
        {
            if (s.empty())
            {
                cout<<(-1)<<' ';
            }
            else
            {
                cout<<s.top()<<' ';
                s.pop();
            }
        }
        else if ("size" == command)
        {
            cout<<s.size()<<' ';
        }
        else if ("empty" == command)
        {
            cout<<(s.empty() ? 1 : 0)<<' ';
        }
        else if ("top" == command)
        {
            cout<<(s.empty() ? -1 : s.top())<<' ';
        }
    }

    return 0;
}