#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v = {70, 20, 32, 40, 33, 60, 32, 33, 90, 50};
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i : v)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}