#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Trie
{
private: 
    bool finish;
    string content;
    map<string, Trie> childs;
public:
    Trie(string _content = "") : content(_content), finish(false) {};
    void Insert(queue<string> &strQueue)
    {
        if(strQueue.empty()) return;

        string str = strQueue.front();
        strQueue.pop();
        if (childs.find(str) == childs.end())
        {
            childs[str] = Trie(str);
        }
        childs[str].Insert(strQueue);
    }
    void ShowContent(int level)
    {
        string output;
        for (int i = 1; i < level; i++)
            output += "--";

        if(level > 0)
        {
            output += content;
            cout<<output<<endl;
        }
        
        for (auto child : childs)
        {
            child.second.ShowContent(level + 1);
        }
    }
};

int main(void)
{
    // 트라이 생성
    Trie root;
    int num;
    cin>>num;

    for (int i = 0; i < num; i++)
    {
        int n;
        queue<string> q;
        cin>>n;
        for (int j = 0; j < n; j++)
        {
            string s;
            cin>>s;
            q.push(s);
        }
        root.Insert(q);
    }


    // 생성된 트라이 출력
    root.ShowContent(0);

    return 0;
}