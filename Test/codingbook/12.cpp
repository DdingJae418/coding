#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> risingPrices;
    for (int i = 0; i < prices.size(); i++)
    {
        if(risingPrices.empty() || risingPrices.top().second <= prices[i])
        {
            risingPrices.push(make_pair(i, prices[i]));
        }
        else
        {
            while(prices[i] < risingPrices.top().second)
            {
                answer[risingPrices.top().first] = i - risingPrices.top().first;
                risingPrices.pop(); 
                if(risingPrices.empty()) break;
            }
            risingPrices.push(make_pair(i, prices[i]));
        }
    }
    while(!risingPrices.empty())
    {  
        answer[risingPrices.top().first] = prices.size() - 1 - risingPrices.top().first;
        risingPrices.pop();
    }
    return answer;
}