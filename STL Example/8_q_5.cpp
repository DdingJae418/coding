#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> v1 = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int> v2(10);
    vector<int> v3(10);

    vector<int>::iterator iter = copy(v1.begin(), v1.end(), v2.begin());
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());

    for (int i : v3)
        cout<<i<<' ';
    cout<<endl;

    return 0;
}