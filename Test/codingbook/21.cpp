#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

void CheckPerson(vector<int> &answer, int num, int size)
{
    answer[0] = (num%size+1);
    answer[1] = (num/size+1);
}

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> wordSet;
    vector<int> answer = {0,0};

    for (int i = 0; i < words.size(); i++)
    {
        // check if it is available
        if(i != 0)
        {
            if (words[i-1][words[i-1].size()-1] != words[i][0])
            {
                CheckPerson(answer, i, n);
                break;
            }
        }

        // check it it is unique
        if(i != 0)
        {
            if(wordSet.find(words[i]) != wordSet.end())
            {
                CheckPerson(answer, i, n);
                break;
            }
        }

        // save word and continue
        wordSet.insert(words[i]);
    }

    return answer;
}