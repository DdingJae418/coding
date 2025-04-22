#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(void)
{
    int N = 0, K = 0;   
    cin>>N>>K;

    int n = 1;
    list<int> ls(N);
    for (int& i : ls)
    {
        i = n++;
    }

    int index = 0;
    vector<int> result;
    while (N)
    {
        index = (index + (K - 1)) % N;
        auto it = ls.begin();
        for (int i = 0; i < index; i++)
            it++;

        result.push_back(*it);
        ls.erase(it);

        N--;
    }

    if (result.size() == 1)
    {
        cout<<'<'<<result[0]<<'>'<<endl;
        return 0;
    }

    for (int i = 0; i < result.size(); i++)
    {
        if (i == 0)
        {
            cout<<'<'<<result[i]<<", ";
        }
        else if (i == result.size() - 1)
        {
            cout<<result[i]<<'>'<<'\n';
        }
        else
        {
            cout<<result[i]<<", ";
        }
    }

    return 0;
}