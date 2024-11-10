#include <iostream>
using namespace std;

class Rectangle
{
private:
    int height;
    int width;
    int area;
public :
    Rectangle(int h, int w) : height(h), width(w), area(h * w) {}
    void ShowAreaInfo()
    {
        cout<<"면적: "<<area<<endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int size) : Rectangle(size, size) {}
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}