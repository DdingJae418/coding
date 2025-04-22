#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> input(8);
    for (int i = 0; i < 8; i++)
    {
        cin>>input[i];
    }

    vector<int> asc = {1,2,3,4,5,6,7,8};
    vector<int> des = {8,7,6,5,4,3,2,1};

    if (equal(input.begin(), input.end(), asc.begin()))
    {
        cout<<"ascendgin"<<endl;
    }
    else if (equal(input.begin(), input.end(), des.begin()))
    {
        cout<<"descending"<<endl;
    }
    else
    {
        cout<<"mixed"<<endl;
    }
}