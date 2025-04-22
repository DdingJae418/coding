#include <iostream>

using namespace std;

int main(void)
{
    int testNum = 0;

    cin>>testNum;

    for (int i = 0; i < testNum; i++)
    {
        int height = 0, width = 0, number = 0;
        int floor = 0, room = 0;

        cin>>height>>width>>number;

        floor = number % height == 0 ? height : number % height;
        room = (number - 1) / height + 1;

        cout<<(floor*100 + room)<<endl;
    }

    return 0;
}