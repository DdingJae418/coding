#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ')')
        {
            if(st.size() == 0)
                return false;
            if(st.top() == '(')
                st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }

    if(st.size() == 0)
        return true;
    else
        return false;
}

int main(void)
{
    cout<<solution("((())()")<<endl;
    return 0;
}