#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int K = 0, N = 0;
    cin>>K>>N;

    vector<unsigned int> vec(K);
    for (unsigned int& v : vec)
    {
        cin>>v;
    }

    unsigned int minLen = 1;
    unsigned int maxLen = *max_element(vec.begin(), vec.end());

    unsigned int result = 0;
    while (minLen <= maxLen)
    {
        unsigned int count = 0;
        unsigned pivot = minLen + (maxLen - minLen) / 2;

        for (unsigned int v : vec)
        {
            count += v / pivot;
        }

        if (N <= count)
        {
            result = pivot;
            minLen = pivot + 1;
        }
        else
        {
            maxLen = pivot - 1;
        }
    }

    cout<<result<<endl;

    return 0;
}