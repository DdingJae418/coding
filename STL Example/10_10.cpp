#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(void)
{
    vector<int> v;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(v));
    
    cout<<"v : ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;

    return 0;
}