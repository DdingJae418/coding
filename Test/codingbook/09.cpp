#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solution(int decimal)
{
    stack<int> st;
    if(decimal == 0)
        return "0";
    while(decimal > 0)
    {
        st.push(decimal % 2);
        decimal /= 2;
    }
    string s = "";
    while(!st.empty())
    {
        s+=to_string(st.top());
        st.pop();
    }

    return s;
}

int main(void)
{
    cout<<solution(10)<<endl;
    return 0;
}