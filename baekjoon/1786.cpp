#include <iostream>
#include <vector>

using namespace std;

int num;
vector<int> idx;
vector<int> failure;

void fail(string pat)
{
    failure[0] = -1;
    int j;

    for (int i = 1; i < pat.length(); i++)
    {
        j = failure[i-1];

        
    }

}

void KMP(string text, string pat)
{

}

int main(void)
{
    string text, pattern;

    getline(cin, text);
    cin>>pattern;
    failure.resize(pattern.length());

    fail(pattern);

    KMP(text, pattern);

    cout<<num<<endl;
    for (int i : idx)
        cout<<i<<' ';
    cout<<endl;
}