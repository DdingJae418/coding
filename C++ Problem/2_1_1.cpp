#include <iostream>
using namespace std;

void AddOne(int& num);
void ChangeSign(int& num);

int main(void)
{
    int num = 1;

    AddOne(num);
    cout<<num<<endl;

    ChangeSign(num);
    cout<<num<<endl;
}

void AddOne(int& num)
{
    num+=1;
}

void ChangeSign(int& num)
{
    num = -num;
}