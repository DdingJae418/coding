#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);

    vector<int> v3(6);

    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));

    return 0;
}