#include <iostream>

using namespace std;

int main(void)
{
    int testNum = 0;
    cin>>testNum;

    for (int i = 0; i < testNum; i++)
    {
        string input;
        cin>>input;
    
        int score = 0;
        int buf = 0;
    
        for (char c : input)
        {
            if (c == 'O')
            {
                buf++;
                score += buf;
            }
            else
            {
                buf = 0;
            }
        }

        cout<<score<<endl;
    }

    return 0;
}