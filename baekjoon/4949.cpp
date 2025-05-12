#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    while (true)
    {
        string str;
        getline(cin, str);

        if (str == ".")
            break;

        stack<char> st;
        bool result = true;
        for (char c : str)
        {
            if (c == '(' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    result = false;
                    break;
                }

                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    result = false;
                    break;
                }

                st.pop();
            }
        }

        if (st.empty() == false)
            result = false;
        
        cout<<(result ? "yes" : "no")<<endl;
    } 

    return 0;
}