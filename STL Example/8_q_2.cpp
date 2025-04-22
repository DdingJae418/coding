#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v = {10, 20, 30,40, 50};

    v.erase(find(v.begin(), v.end(), 30));

    for (int i : v)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}