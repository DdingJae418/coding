#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    int testNum = 0;
    cin>>testNum;
    
    while (testNum--)
    {
        string ps;
        cin>>ps;

        stack<char> st;
        bool isVPS = true;
        for (char c : ps)
        {
            if (c == '(')
            {
                st.push(c);
            }
            else 
            {
                if (st.empty())
                {
                    isVPS = false;
                    break;
                }
                else
                {
                    st.pop();
                }

            }
        }

        cout<<(isVPS && st.empty() ? "YES" : "NO")<<endl;
    }

    return 0;
}