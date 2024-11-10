#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> comb;

void combination(const string &src, const string &dest, int depth)
{
    if (dest.size() == depth) comb[dest]++;
    else
    {
        for (int i = 0; i < src.size(); i++)
            combination(src.substr(i+1), dest + src[i], depth);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (string &order : orders)
        sort(order.begin(), order.end());

    for (int len : course)
    {
        for (string &order : orders) 
            combination(order, "", len);

        int maxOrder = 0;
        for (auto it : comb)
            maxOrder = max(maxOrder, it.second);
        if (maxOrder < 2) continue;
        
        for (auto it : comb)
        {
            if (it.second == maxOrder)
                answer.push_back(it.first);
        }

        comb.clear();
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2,3,4});
}