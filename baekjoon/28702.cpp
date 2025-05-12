#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isNumber(string s)
{
    return '0' < s[0] && s[0] <= '9';
}

int main(void)
{
    vector<string> strVec(3);
    for (auto it = strVec.begin(); it != strVec.end(); it++)
    {
        cin>>*it;
    }

    int idx = 0;
    int num = 0;
    for (int i = 0; i < 3; i++)
    {
        if (isNumber(strVec[i]))
        {
            num = stoi(strVec[i]);
            idx = i; 
            break;
        }
    }

    int next = num + 3 - idx;

    if (next % 3 == 0 && next % 5 == 0)
        cout<<"FizzBuzz"<<endl;
    else if (next % 3 == 0)
        cout<<"Fizz"<<endl;
    else if (next % 5 == 0)
        cout<<"Buzz"<<endl;
    else
        cout<<next<<endl;

    return 0;
}