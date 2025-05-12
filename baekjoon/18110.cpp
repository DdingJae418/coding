#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
    int n = 0;
    cin>>n;

    if (0 == n)
    {
        cout<<0<<endl;
        return 0;
    }

    int exclude = round(n * 0.15);

    vector<int> vec(n);
    for (auto &i : vec)
    {
        cin>>i;
    }

    sort(vec.begin(), vec.end());

    int sum = accumulate(vec.begin() + exclude, vec.end() - exclude, 0);
    int result = round(sum / (n - 2.0 * exclude));

    cout<<result<<endl;

    return 0;
}