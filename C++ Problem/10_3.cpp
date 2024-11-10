#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

    void ShowPoisition() const
    {
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }

    friend ostream& operator<<(ostream &os, const Point &ref);
    friend istream& operator>>(istream &is, Point &ref);
};

ostream& operator<<(ostream &os, const Point &ref)
{
    os<<'['<<ref.xpos<<", "<<ref.ypos<<']'<<endl;
    return os;
}

istream& operator>>(istream &is, Point &ref)
{
    is>>ref.xpos>>ref.ypos;
    return is;
}



int main(void)
{
    Point pos1;
    cout<<"좌표 입력: ";
    cin>>pos1;
    cout<<pos1;
}