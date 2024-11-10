#include <iostream>
#include <vector>
using namespace std;

int solution(int N, int K)
{
    if(N==1) return 1;

    vector<int> next(N);
    vector<int> prev(N);
    int current = 0;
    for (int i = 0; i < N; i++)
    {
        next[i] = (i + 1) % N;
        prev[i] = (N - 1 + i) % N;
    }

    do
    {
        for(int i = 0; i < K - 1; i++)
        {
            current = next[current];
        }
        next[prev[current]] = next[current];
        prev[next[current]] = prev[current];
        current = next[current];
    } while (next[current] != current);
    
    return current + 1;
}

int main(void)
{
    cout<<solution(5,2)<<endl;
}