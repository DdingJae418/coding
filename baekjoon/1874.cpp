#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    int n = 0;
    cin>>n;

    vector<int> vec(n);
    for (int& v : vec)
    {
        cin>>v;
    }

    stack<int> s;
    auto p = vec.begin();
    vector<char> result;
    for(int i = 1; i <= n; i++)
    {
        s.push(i);
        result.push_back('+');

        while(false == s.empty() && s.top() == *p)
        {
            s.pop();
            result.push_back('-');

            p++;
        }
    }
    
    if (p == vec.end())
    {
        for (char c : result)
        {
            cout<<c<<'\n';
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}