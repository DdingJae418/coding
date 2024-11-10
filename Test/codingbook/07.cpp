#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;
public: 
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const
    {
        return (other.x) == x && (other.y == y);
    }
    void SetPoint(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int GetX() const {return x;}
    int GetY() const {return y;}
};

class Path
{
private:
    Point point1, point2;
public:
    Path(Point p1, Point p2) : point1(p1), point2(p2) {}
    bool operator==(const Path& other) const
    {
        if(((point1 == other.point1) && (point2 == other.point2)) ||
            ((point1 == other.point2) && (point2 == other.point1)))
            return true;
        else
            return false;
    }
};  

class Character
{
private:
    Point currentPoint;
    vector<Path> passedPath;
public:
    Character() : currentPoint(0,0) {}
    void Move(char move)
    {
        Point nextPoint;
        switch(move)
        {
        case 'U':
            nextPoint.SetPoint(currentPoint.GetX(), currentPoint.GetY() + 1);
            break;
        case 'D':
            nextPoint.SetPoint(currentPoint.GetX(), currentPoint.GetY() - 1);
            break;        
        case 'R':
            nextPoint.SetPoint(currentPoint.GetX() + 1, currentPoint.GetY());
            break;
        case 'L':
            nextPoint.SetPoint(currentPoint.GetX() - 1, currentPoint.GetY());
            break;
        }

        if(nextPoint.GetX() > 5 || nextPoint.GetX() < -5)
            return;
        if(nextPoint.GetY() > 5 || nextPoint.GetY() < -5)
            return;

        passedPath.push_back(Path(currentPoint, nextPoint));
        currentPoint = nextPoint;
    }
    int GetMoveRange()
    {
        vector<Path> rangeVector;
        for(int i = 0; i < passedPath.size(); i++)
        {
            bool same = false;
            for(int j = 0; j < rangeVector.size(); j++)
            {
                if(rangeVector[j] == passedPath[i])
                {
                    same = true;
                    break;
                }
            }
            if(!same) rangeVector.push_back(passedPath[i]);
        }
        return rangeVector.size();
    } 
    void ShowCurrentPoint() const { cout<<currentPoint.GetX()<<' '<<currentPoint.GetY()<<endl;}
};

int solution(string dirs) {
    Character character;
    for (int i = 0; i< dirs.length(); i++)
    {
        character.Move(dirs[i]);
    }

    return character.GetMoveRange();
}

int main(void)
{
    pair<int, int> p1(1,1);
    pair<int, int> p2(1,2);
    cout<<(p1==p2)<<endl;
}