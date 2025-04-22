#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 0;
    cin>>N;
    unordered_map<int, int> umap;
    while (N--)
    {
        int number = 0;
        cin>>number;

        umap[number]++;
    }

    int M = 0;
    cin>>M;
    while (M--)
    {
        int number = 0;
        cin>>number;

        cout<<(umap.end() == umap.find(number) ? 0 : umap[number])<<' ';
    }

    return 0;
}