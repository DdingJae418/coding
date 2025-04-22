#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
struct Plus
{
    T operator () (const T& left, const T& right) const
    {
        return left + right;
    }
};

int main(void)
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

}