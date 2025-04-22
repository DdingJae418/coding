#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    while(true)
    {
        vector<int> nums(3);
        for (int i = 0; i < 3; i++)
        {
            cin>>nums[i];
        }

        if (nums[0] == 0)
            break;

        sort(nums.begin(), nums.end());

        if (nums[0]*nums[0] + nums[1]*nums[1] == nums[2]*nums[2])
            cout<<"right"<<endl;
        else   
            cout<<"wrong"<<endl;
    }

    return 0;
}