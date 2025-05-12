#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int N = 0;
    cin>>N;

    int pow[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

    vector<int> vec;
    vec.reserve(40000);
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int head = i / pow[j] * pow[3 + j];
            int mid = 666 * pow[j];
            int tail = i % pow[j];

            vec.push_back(head + mid + tail);
        }
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout<<vec[N - 1]<<endl;

    return 0;
}