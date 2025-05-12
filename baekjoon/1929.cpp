#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int M = 0, N = 0;
    cin>>M>>N;

    vector<bool> vec(N + 1, true);

    vec[0] = false;
    vec[1] = false;

    for (int i = 2; i < N + 1; i++ )
    {
        if (vec[i] == false)
            continue;
        
        for (int j = 2; i * j <= N; j++)
        {
            vec[i * j] = false;
        }
    }


    for (int i = M; i <= N; i++)
    {
        if (vec[i])
            cout<<i<<'\n';
    }

    return 0;
}