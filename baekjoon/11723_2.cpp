#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin>>M;

    vector<bool> vec(20);

    while (M--)
    {
        string cmd;
        int x;
        cin>>cmd;

        if ("add" == cmd)
        {
            cin>>x;
            vec[x-1] = true;
        }
        else if ("remove" == cmd)
        {
            cin>>x;
            vec[x-1] = false;
        }
        else if ("check" == cmd)
        {
            cin>>x;
            cout<<vec[x-1]<<'\n';
        }
        else if ("toggle" == cmd)
        {
            cin>>x;
            vec[x-1] = !vec[x-1];
        }
        else if ("all" == cmd)
        {
            for (int i = 0; i < 20; i++)
            {
                vec[i] = true;
            }
        }
        else if ("empty" == cmd)
        {
            for (int i = 0; i < 20; i++)
            {
                vec[i] = false;
            }
        }
    }

    return 0;
}