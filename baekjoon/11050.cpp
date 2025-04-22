#include <iostream>

using namespace std;

int factorial(int num)
{
    if (num < 2)
        return 1;
    
    return num * factorial(num - 1);
}

int main(void)
{
    int N = 0, K = 0;
    cin>>N>>K;

    cout<<(factorial(N) / (factorial(N - K) * factorial(K)));
}