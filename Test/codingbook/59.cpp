#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const string &s1, const string &s2) 
    {
        if(s1.length() == s2.length())
        {
            return s1 < s2;
        }
        else
        {
            int case1 = stoi(s1 + s2);
            int case2 = stoi(s2 + s1);

            return case1 < case2;
        }
    }
};

string solution(vector<int> numbers) {
    string answer = "";
    priority_queue<string, vector<string>, Compare> pq;

    for (int i : numbers)
        pq.push(to_string(i));
    
    while(!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    if(answer[0] == '0') return "0";
    else
        return answer;
}