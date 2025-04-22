#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int size = 0;
    cin>>size;

    vector<int> vec(size);

    while(size--)
    {
        cin>>vec[size];
    }

    sort(vec.begin(), vec.end());

    for (int i : vec)
    {
        cout<<i<<'\n';
    }

    return 0;
}