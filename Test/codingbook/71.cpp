#include <vector>

using namespace std;


int solution(const vector<int> nums)
{
    vector<int> dp(nums.size(), 0);

    for (int i = 0; i < nums.size(); i++)
    {
        if(i == 0 )
        {
            dp[i] = 1;
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i]++;
        }
    }

    return *max_element(dp.begin(), dp.end());
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution({1, 4, 2, 3, 1, 5, 7, 3}) << endl; //출력값 : 5
  cout << solution({3, 2, 1}) << endl; //출력값 : 1
  
  return 0;
}