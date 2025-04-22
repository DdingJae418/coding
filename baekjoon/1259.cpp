#include <iostream>

using namespace std;

int main(void)
{
    string num;

    while (true)
    {
        cin>>num;
        if (num == "0")
            break;

        bool isPalin = true;
        int len = num.length();
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (num[i] != num[len - 1 - i])
            {
                isPalin = false;
                break;
            }
        }
        
        cout<<(isPalin ? "yes" : "no")<<endl;
    }

    return 0;
}