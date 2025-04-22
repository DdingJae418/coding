#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int A = 0, B = 0, C = 0;
    int result = 0;
    vector<int> count(10);

    cin>>A>>B>>C;

    result = A * B * C;

    while (0 < result)
    {
        int num = result % 10;
        count[num]++;
        result /= 10;
    }

    for (int num : count)
    {
        cout<<num<<endl;
    }

    return 0;
}