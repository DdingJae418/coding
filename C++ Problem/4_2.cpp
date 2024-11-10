#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public: 
    void Init(int x, int y)
    {
        xpos=x;
        ypos=y;
    }
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
    void Init(Point &cent, int rad)
    {
        center = cent;
        radius = rad;
    }
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
    void Init(int ix, int iy, int irad, int ox, int oy, int orad)
    {
        Point innerCenter, outerCenter;
        innerCenter.Init(ix, iy);
        outerCenter.Init(ox, oy);
        
        innerCircle.Init(innerCenter, irad);
        outerCircle.Init(outerCenter, orad);
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
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}