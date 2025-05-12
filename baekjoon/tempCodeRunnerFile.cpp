#include <iostream>

using namespace std;

int factorial(int n)
{
    if (n < 2)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(void)
{
    int N = 0;
    cin>>N;

    int result = factorial(N);
    int count = 0;
    while (0 < result)
    {
        if (result % 10 == 0)
            count++;
        result /= 10;
    }   

    cout<<count<<endl;

    return 0;
}