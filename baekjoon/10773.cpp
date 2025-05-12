#include <iostream>
#include <stack>
#include <numeric>

using namespace std;

int main(void)
{
    int K = 0;
    cin>>K;

    stack<int> st;

    while (K--)
    {
        int num = 0;
        cin>>num;

        if (num == 0)
        {
            st.pop();
        }
        else
        {
            st.push(num);
        }
    }

    int result = 0;
    while (st.empty() == false)
    {
        result += st.top();
        st.pop();
    }

    cout<<result<<endl;

    return 0;
}