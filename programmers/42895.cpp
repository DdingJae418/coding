#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<unordered_set<int>> dp(9);
    dp[0].insert(0);
    dp[1].insert(N);
    
    for (int i = 2; i <= 8; i++)
    {
        int num = N;
        for (int j = 1; j < i; i++)
        {
            num*=10;
            num+=N;
        }
        dp[i].insert(num);
        
        for (int j = 1; j < )
        
    }
    
    return -1;
}