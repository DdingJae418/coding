#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> numbers;
    vector<pair<int, int>> nums;
    string num = "";

    // 각 숫자가 등장한 횟수 세기
    for (char c : s)
    {
        if(c >= '0' && c <= '9')
        {
            num += c;
        }
        else
        {
            if(num.length() > 0) numbers[stoi(num)]++;
            num = "";
        }
    }

    nums.assign(numbers.begin(), numbers.end());
    sort(nums.begin(), nums.end(), compare);

    for (auto n : nums)
    {
        answer.push_back(n.first);
    }
    return answer;
}