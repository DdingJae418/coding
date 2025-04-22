#include <iostream>
#include <vector>

using namespace std;

vector<int> fail(string pt)
{
    vector<int> table(pt.length(), 0);
    int j = 0;

    for (int i = 1; i < pt.length(); i++)
    {
        while (j > 0 && pt[j] != pt[i])
        {
            j = table[j-1];
        }
        if(pt[j] == pt[i])
        {
            table[i] = ++j;
        }
    }

    return table;
}

pair<int, vector<int>> KMP(string txt, string pt)
{
    vector<int> table = fail(pt);
    vector<int> pos;
    int num = 0;
    int j = 0;

    for (int i = 0; i < txt.length(); i++)
    {
        while (j > 0 && txt[i] != pt[j])
        {
            j = table[j - 1];
        }
        if(txt[i] == pt[j])
        {
            if (j == pt.size() - 1)
            {
                j = table[j];
                num++;
                pos.push_back(i - pt.length() + 2);
            }
            else
            {
                j++;
            }
        }
    }

    return {num, pos};
}

int main(void)
{
    string text;
    string pattern;

    getline(cin, text);
    getline(cin, pattern);

    auto answers = KMP(text, pattern);

    cout<<answers.first<<endl;

    for (int i = 0; i < answers.second.size(); i++)
    {
        if(i == 0)
            cout<<answers.second[i];
        else
            cout<<' '<<answers.second[i];
    }
    cout<<endl;

    return 0;
}