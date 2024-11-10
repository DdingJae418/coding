#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public: 
    Point(int x, int y) : xpos(x), ypos(y) {}
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    Point center;
    int radius;
public:
    Circle(int x, int y, int rad) : center(x, y), radius(rad) {}
    void ShowCircleInfo() const
    {
        cout<<"radius: "<<radius<<endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle innerCircle;
    Circle outerCircle;
public:
    Ring(int ix, int iy, int irad, int ox, int oy, int orad) 
        : innerCircle(ix, iy, irad), outerCircle(ox, oy, orad)
    {
    }
    void ShowRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        innerCircle.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        outerCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}