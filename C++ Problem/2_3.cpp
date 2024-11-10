#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *newPoint = new Point;
    newPoint->xpos = p1.xpos + p2.xpos;
    newPoint->ypos = p1.ypos + p2.ypos;
    return *newPoint;
}

int main(void)
{
    Point *p1 = new Point;
    p1->xpos = 10;
    p1->ypos = 20;
    Point *p2 = new Point;
    p2->xpos = 20;
    p2->ypos = 30;
    Point &sum = PntAdder(*p1, *p2);

    cout<<sum.xpos<<' '<<sum.ypos<<endl;

    delete p1;
    delete p2;
    delete &sum;
}