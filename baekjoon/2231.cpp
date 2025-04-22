#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int N = 0;
    vector<int> vec;
    cin>>N;

    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        int num = i;

        sum += num;
        while (0 < num)
        {
            sum += num % 10;
            num /= 10;
        }

        if (N == sum)
        {
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<0<<endl;

    return 0;
}