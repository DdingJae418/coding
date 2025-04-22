#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int L;
    string text;

    cin>>L;
    cin>>text;

    vector<int> table(L, 0);
    int j = 0;
    for (int i = 1; i < L; i++)
    {
        while (j > 0 && text[j] != text[i])
        {
            j = table[j-1];
        }
        if(text[j] == text[i])
        {
            table[i] = ++j;
        }
    }

    cout<<(L - table[L-1])<<endl;

    return 0;
}