#include <iostream>

using namespace std;

int main(void)
{
    int A = 0, B = 0, V = 0;
    cin>>A>>B>>V;

    int day = ((V - A) + (A - B) - 1) / (A - B) + 1;

    cout<<day<<endl;

    return 0;
}