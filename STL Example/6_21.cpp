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

    vector<int>::iterator iter = v.begin() + 2;
    vector<int>::iterator iter2;

    iter2 = v.insert(iter, 100);

    cout<<*iter2<<endl;
    
    return 0;
}