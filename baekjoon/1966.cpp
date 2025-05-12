#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    int test = 0;
    cin>>test;

    while(test--)
    {
        int N = 0, M = 0;
        cin>>N>>M;

        queue<pair<int, int>> q;
        map<int, int, greater<int>> m;
        for (int i = 0; i < N; i++)
        {
            int priority = 0;
            cin>>priority;

            q.push(make_pair(i, priority));
            m[priority]++;
        }

        int result = 1;
        while(true)
        {
            auto f = q.front();
            q.pop();

            if (f.second == m.begin()->first)
            {
                if (f.first == M)
                {
                    cout<<result<<'\n';
                    break;
                }

                m.begin()->second--;
                if (m.begin()->second <= 0)
                    m.erase(f.second);
                
                result++;
            }
            else
            {
                q.push(f);
            }
        }
    }

    return 0;
}