#include <iostream>
#include <vector>

using namespace std;

class Trie
{
private:
    bool finish;
    Trie* childs[27];
public:
    Trie() : finish(false) 
    {
        for (Trie*& t : childs)
            t = nullptr;
    }
    ~Trie()
    {
        for (Trie* t : childs)
            delete t;
    }
    void Insert(string& str, string::iterator iter)
    {
        if(iter == str.end())
        {
            finish = true;
            return;
        }
        char c = *iter;
        if(childs[int(c-'a')] == nullptr)
        {
            childs[int(c-'a')] = new Trie();
        }
        childs[int(c-'a')]->Insert(str, ++iter);
    }
    bool Find(string& str, string::iterator iter)
    {
        if(iter == str.end())
        {
            if(finish) return true;
            else return false;
        }
        
        char c = *iter;
        if(childs[int(c-'a')] == nullptr)
            return false;
        else
            return childs[int(c-'a')]->Find(str, ++iter);
    }
};

int main(void)
{
    Trie root;
    int n, m;
    int nums = 0;

    cin>>n>>m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        root.Insert(s, s.begin());
    }

    for (int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        if(root.Find(s, s.begin())) 
            nums++;
    }

    cout<<nums;

    return 0;
}