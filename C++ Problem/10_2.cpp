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

    Point operator+(const Point &pos) const
    {
        return Point(xpos - pos.xpos, ypos - pos.ypos);
    }

    Point& operator+=(const Point &point)
    {
        xpos += point.xpos;
        ypos += point.ypos;
        return *this;
    }
    Point& operator-=(const Point &point)
    {
        xpos -= point.xpos;
        ypos -= point.ypos;
        return *this;
    }

    Point operator-()
    {
        return Point(-xpos, -ypos);
    }

    friend Point operator+(const Point &pos1, const Point &pos2);
    friend Point operator-(const Point &pos1, const Point &pos2);
    friend bool operator==(const Point &pos1, const Point &pos2);
    friend Point operator~(const Point &ref);
};

Point operator+(const Point &pos1, const Point &pos2)
{
    return Point(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}
Point operator-(const Point &pos1, const Point &pos2)
{
    return Point(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
}

bool operator==(const Point &pos1, const Point &pos2)
{
    return (pos1.xpos == pos2.xpos) && (pos1.ypos == pos2.ypos);
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    return !(pos1 == pos2);
}

Point operator~(const Point &ref)
{
    return Point(ref.ypos, ref.xpos);
}

int main(void)
{
    Point p1(1,2);
    Point p2(2,3);
    cout<<(p1!=p2);
}