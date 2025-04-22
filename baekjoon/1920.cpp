#include <iostream>
#include <unordered_set>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    unordered_set<int> set1;
    cin>>N;
    while (N--)
    {
        int number = 0;
        cin>>number;
        set1.insert(number);
    }

    int M = 0;
    cin>>M;
    while (M--)
    {
        int number = 0;
        cin>>number;
        cout<<(set1.end() == set1.find(number) ? 0 : 1)<<'\n';
    }

    return 0;
}