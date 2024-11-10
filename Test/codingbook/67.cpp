#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int width, height = 3;

    while(true)
    {
        if((brown + yellow) % height != 0)
        {
            height++; 
            continue;
        }
        width = (brown + yellow) / height;

        if(yellow == (height-2)*(width-2))
            break;
    
        height++;
    }

    answer.push_back(width);
    answer.push_back(height);

    return answer;
}