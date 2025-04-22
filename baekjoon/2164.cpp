#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    int N = 0; 
    cin>>N;

    int i = 1;
    list<int> cards(N);
    for (int& card : cards)
    {
        card = i++;
    }

    bool removeCard = true;

    while (1 < cards.size())
    {
        if (false == removeCard)
            cards.push_back(*cards.begin());   
            
        cards.erase(cards.begin());

        removeCard = !removeCard;
    }

    cout<<*cards.begin()<<endl;

    return 0;
}