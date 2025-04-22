#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

class Trie
{
private: 
    bool isFinish;
    vector<Trie*> next;
public:
    Trie() : isFinish(false), next(26, nullptr) { }
    void InsertTrie(string s)
    {
        Trie* cur = this;

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];

            if(cur->next[c-'a'] == nullptr)
                cur->next[c-'a'] = new Trie();
                
            cur = cur->next[c-'a'];
            if(i == s.length()-1)
                cur->isFinish = true;
        }
    }
    void CheckClickNumber(string s, double& sum)
    {
        Trie* cur = next[s[0]-'a'];
        sum++;

        for (int i = 1; i < s.length(); i++)
        {
            if(count(cur->next.begin(), cur->next.end(), nullptr) != 25 || cur->isFinish)
                sum++;
            cur = cur->next[s[i]-'a'];
        }
    }
    ~Trie()
    {
        for (auto t : next)
            if(t != nullptr)
                delete t;
    }

};

int main(void)
{
    int num;
    while(cin>>num)
    {
        // 단어 입력
        vector<string> v(num);
        for (int i = 0; i < num; i++)
        {
            string s;
            cin>>s;
            v[i] = s;
        }

        // Trie 생성
        Trie root;
        for (string s : v)
            root.InsertTrie(s);

        // 평균 횟수 계산 및 출력
        double sum = 0;
        for (string s : v)
            root.CheckClickNumber(s, sum);

        cout<<fixed<<setprecision(2)<<(sum / num)<<endl;
    }

    return 0;
}