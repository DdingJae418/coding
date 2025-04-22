#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin>>num;
        sum+=num*num;
    }
    cout<<(sum%10)<<endl;

    return 0;
}