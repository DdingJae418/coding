#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(void)
{
    string line;
    getline(cin, line);
    istringstream iss(line);

    int prevNum = 0;;
    int curNum = 0;
    while(iss>>curNum)
    {
        if (prevNum == 0 || abs(curNum - prevNum) == 1)
        {
            prevNum = curNum;
        }
        else 
        {
            cout<<"mixed"<<endl;
            return 0;
        }
    }

    curNum == 8 ? cout<<"ascending"<<endl : cout<<"descending"<<endl;

    return 0;
}