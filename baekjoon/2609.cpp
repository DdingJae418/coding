#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int num1 = 0, num2 = 0;
    int minNum = 0, maxNum = 0;

    cin>>num1>>num2;

    int std = min(num1, num2);
    for (int i = 1; i <= std; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            minNum = i;
    }

    maxNum = minNum * (num1 / minNum) * (num2 / minNum);

    cout<<minNum<<'\n'<<maxNum;

    return 0;
}