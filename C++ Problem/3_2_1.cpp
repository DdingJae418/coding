#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Calculator
{
private:
    int addNum;
    int subNum;
    int mulNum;
    int divNum;
public:
    void Init()
    {
        addNum = 0;
        subNum = 0;
        mulNum = 0;
        divNum = 0;
    }

    float Add(float a, float b)
    {
        addNum++;
        return a+b;
    }

    float Min(float a, float b)
    {
        subNum++;
        return a-b;
    }

    float Mul(float a, float b)
    {
        mulNum++;
        return a*b;
    }

    float Div(float a, float b)
    {
        divNum++;
        return a/b;
    }

    void ShowOpCount()
    {
        cout<<addNum<<" "<<subNum<<" "<<mulNum<<" "<<divNum<<endl;
    }
};

int main(void)
{
    Calculator cal;
    cal.Init();
    cout<<cal.Add(3.2, 2.4)<<endl;
    cout<<cal.Div(3.5, 1.7)<<endl;
    cout<<cal.Min(2.2, 1.5)<<endl;
    cout<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
}