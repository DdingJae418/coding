#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;

    vector<int> vec(10000);
    while (N--)
    {
        int i = 0;
        cin>>i;
        vec[i - 1]++;
    }

    for(int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i]; j++)
        {
            cout<<i+1<<'\n';
        }
    }

    return 0;
}