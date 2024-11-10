#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

long long hashFunc(const string &str)
{
    int p = 31;
    long long m = 1000000007;
    long long hashNum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if(i == 0) 
        {
            hashNum = str[i]%m;
        }
        else
        {
            hashNum += (str[i]*p)%m;
            p*=p;
        }
    }
    return hashNum%m;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
    unordered_set<long long> hash;
    vector<bool> answer(query_list.size(), false);

    // save string list in hash table
    for (int i = 0; i < string_list.size(); i++)
    {
        hash.insert(hashFunc(string_list[i]));
    }

    // find query in hash table 
    for (int i = 0; i < query_list.size(); i++)
    {
        if(hash.find(hashFunc(query_list[i])) != hash.end())
        {
            answer[i] = true;
        }
        else
        {
            answer[i] = false;
        }
    }

    return answer;    
}

int main(void)
{
    vector<bool> answer = solution({"apple", "banana", "cherry"}, {"banana", "kiwi", "melon", "apple"});

    for (bool ans : answer)
        cout<<ans;
    return 0;
}