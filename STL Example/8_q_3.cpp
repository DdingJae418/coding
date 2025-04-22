#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    reverse(v.begin(), v.begin() + v.size()/2);

    for (int i : v)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}