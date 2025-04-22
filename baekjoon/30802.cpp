#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> sizes(6);
    int N = 0;
    int T = 0, P = 0;
    int tnum = 0;

    cin>>N;
    for (int& s : sizes)
    {
        cin>>s;
    }
    cin>>T>>P;

    for (int s : sizes)
    {
        tnum += (s - 1 + T)  / T;
    } 
    cout<<tnum<<endl;
    cout<<(N/P)<<' '<<(N%P)<<endl;

    return 0;
}