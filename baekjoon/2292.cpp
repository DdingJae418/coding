#include <iostream>

using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;
    int dist = 0;
    int lastNum = 1;
    while (true)
    {
        lastNum += dist * 6;
        dist++;
        
        if (N <= lastNum)
        {
            cout<<dist<<endl;
            break;
        }
    }

    return 0;
}