#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v1 = {10, 20, 20, 30, 40, 50};
    vector<int> v2 = {20, 30, 60};
    vector<int> v3(10);
    vector<int>::iterator iter_end;

    iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for (vector<int>::iterator iter = v3.begin(); iter != iter_end; iter++)
        cout<<*iter<<" ";
    cout<<endl;

    return 0;
}