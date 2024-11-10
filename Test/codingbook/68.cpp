#include <iostream>
using namespace std;

int solution(int n)
{
    int moveNum = 0;

    while(n > 0)
    {
        if(n%2 == 1)
        {
            n -= 1;
            moveNum++;
        }

        n/=2;
    }
    
    return moveNum;
}