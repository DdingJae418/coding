#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    int L = 0;
    string str;
    cin>>L>>str;

    long long result = 0;
    long long r = 1;
    for (int i = 0; i < L; i++)
    {
        long long a = str[i] - 'a' + 1;
        result += a * r;
        r = r * 31 % 1234567891;
    }

    cout<<result % 1234567891<<endl;

    return 0;
}