#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
    int num = 0;
    cin>>num;

    while(num--)
    {
        int k = 0, n = 0;
        cin>>k>>n;

        vector<int> prev(n);
        for (int i = 0; i < prev.size(); i++)
        {
            prev[i] = i + 1;
        }

        vector<int> next(n);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < prev.size(); j++)
            {
                next[j] = accumulate(prev.begin(), prev.begin() + j + 1, 0);
            }
            prev = next;
        }

        cout<<next[n-1]<<endl;
    }

    return 0;
}