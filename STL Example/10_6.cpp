#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator iter = v.begin() + 1;
    vector<int>::const_iterator citer = iter;
    reverse_iterator<vector<int>::iterator> riter(iter);
    reverse_iterator<vector<int>::const_iterator> criter(iter);

    cout<<*iter<<endl;
    cout<<*citer<<endl;
    cout<<*riter<<endl;
    cout<<*criter<<endl;

    return 0;
}