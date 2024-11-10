#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map <string, int> compMap;
    
    // make completion map
    for (int i = 0; i < completion.size(); i++)
    {
        if(compMap.find(completion[i]) != compMap.end())
        {
            compMap[completion[i]]++;
        }
        else
        {
            compMap.insert(make_pair(completion[i], 1));
        }
    }

    // find loser
    for (string part : participant)
    {
        if((compMap.find(part) == compMap.end()) || (compMap[part] == 0))
        {
            return part;
        }
        else
        {
            compMap[part]--;
        }
    }

    return answer;
}