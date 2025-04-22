#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
    vector<int> v1 = { 50, 10, 30, 80, 60 };
    vector<int> v2 = { 20, 70, 40 };
    vector<int> v3;

    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3, v3.begin()));

    for (int i : v3)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}
