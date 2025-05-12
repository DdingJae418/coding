#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

constexpr int IntMax = numeric_limits<int>::max();

int main(void)
{
    int N = 0;
    cin>>N;

    vector<int> dp(5000, IntMax);
    dp[2] = 1;
    dp[4] = 1;

    for (int i = 0; i < N; i++)
    {
        if (i < 5) continue;

        int prev = min(dp[i - 3], dp[i - 5]);
        if (prev != IntMax)
        {
            dp[i] = prev + 1;
        }
    }

    cout<<(dp[N-1] == IntMax ? -1 : dp[N-1])<<endl;

    return 0;
}