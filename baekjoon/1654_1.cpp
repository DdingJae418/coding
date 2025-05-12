#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main(void)
{
    int K = 0, N = 0;
    cin>>K>>N;

    vector<int> vec(K);
    for (auto& v : vec)
    {
        cin>>v;
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int minCount = ceil(N / static_cast<double>(K));
    int minUnit = 0;
    while (true)
    {
        int sum = 0;
        int unit = *vec.begin() / (minCount + 1) + 1;

        for (int i = 0; i < K; i++)
        {
            int count = vec[i] / unit;
            sum += count;

            if (count == 0)
                break;
        }

        if (N <= sum)
        {
            minUnit = unit;
            break;
        }
        
        minCount++;
    }

    while (true)
    {
        int newUnit = minUnit + 1;
        int sum = 0;

        for (int i = 0; i < K; i++)
        {
            int count = vec[i] / newUnit;
            sum += count;

            if (count == 0)
                break;
        }

        if (sum < N)
            break;
        
        minUnit = newUnit;
    }

    cout<<minUnit<<endl;

    return 0;
}