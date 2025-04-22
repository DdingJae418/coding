#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> cardPick;
vector<int> cards;
int result = 0;
int N = 0, M = 0;

void pickCard(int i)
{
    if (3 == cardPick.size())
    {
        int newResult = 0;
        for (int num : cardPick)
            newResult += num;

        if (newResult <= M)
            result = max(result, newResult);

        return;
    }

    if (cards.size() == i)
        return;

    cardPick.push_back(cards[i]);
    pickCard(i + 1);
    
    cardPick.pop_back();
    pickCard(i + 1);
}

int main(void)
{
    cin>>N>>M;

    cards.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin>>cards[i];
    }


    pickCard(0);

    cout<<result<<endl;

    return 0;
}