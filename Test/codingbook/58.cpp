#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> command : commands)
    {
        auto first = array.begin();
        for (int i = 1; i < command[0]; i++)
            first++;
        auto second = first + 1;
        for (int i = command[0]; i < command[1]; i++)
            second++;

        
        vector<int> subArr(first, second);
        sort(subArr.begin(), subArr.end());
        answer.push_back(subArr[command[2]-1]);
    }
    return answer;
}