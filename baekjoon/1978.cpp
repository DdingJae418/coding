#include <iostream>

using namespace std;

int main(void)
{
    int result = 0;
    int N = 0;
    cin>>N;

    while (N--)
    {
        int num = 0, i = 0;
        int count = 0;
        cin>>num;

        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
                count++;

            if (2 < count)
                break;
        }

        if (2 == count)
            result++;
    }

    cout<<result<<endl;

    return 0;
}