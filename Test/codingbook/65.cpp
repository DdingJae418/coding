#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int transNum = 0;
    int deleteNum = 0;

    while(s != "1")
    {
        // 0을 제거
        int znum = count(s.begin(), s.end(), '0');
        deleteNum += znum;
        int len = s.length() - znum;

        // 이진수 변환
        s = "";
        stack<int> stk;
        while(len > 0)
        {
            stk.push(len%2);
            len/=2;
        }
        while(!stk.empty())
        {
            s += to_string(stk.top());
            stk.pop();
        }
        transNum++;
    }

    answer.push_back(transNum);
    answer.push_back(deleteNum);
    return answer;
}