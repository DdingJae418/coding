#include <iostream>
#include <set>
#include <iostream>

using namespace std;

bool solution(vector<int> arr, int target)
{
    // change arr to set
    set<int> numbers;
    for(int i =0; i<arr.size(); i++)
    {
        numbers.insert(arr[i]);
    }

    // for every number, find target - number in the set
    for (int i = 0; i < arr.size(); i++)
    {
        int finding = target - arr[i];
        if(finding <= 0) continue;
        else
        {
            if(numbers.find(finding) != numbers.end()) 
            {
                if(*numbers.find(finding) != arr[i])
                    return true;
            }
        }
    }

    return false;
}

int main(void)
{
    cout<<solution({1,2,3,4}, 14)<<endl;
}