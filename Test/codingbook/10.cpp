#include <string>
#include <stack>
#include <iostream>

using namespace std;

bool Check(const string &s)
{
    stack<char> st;

    for (char c : s)
    {
        if((c == '(') || (c == '[') || (c =='{'))
            st.push(c);
        else
        {
            if(st.empty()) 
                return false;
            else
            {
                switch(c)
                {
                case ']':
                    if(st.top() == '[') st.pop();
                    else return false;
                    break;
                case '}':
                    if(st.top() == '{') st.pop();
                    else return false;
                    break;
                case ')':
                    if(st.top() == '(') st.pop();
                    else return false;
                    break;
                default:
                    return false;
                }
            }
        }
    }
    return st.empty();
}

void RotateString(string &s)
{
    string newString = s.substr(1);
    newString += s[0];
    s = newString;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (Check(s)) answer++;
        RotateString(s);
    }

    return answer;
}