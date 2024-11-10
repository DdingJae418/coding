#include <vector>

using namespace std;

vector<int> solution(int amount)
{
    vector<int> answer;

    if(amount >= 100)
    {
        int n = amount / 100;
        for (int i = 0; i < n; i++)
            answer.push_back(100);
        amount %= 100;
    }

    if(amount >= 50)
    {
        int n = amount / 50;
        for (int i = 0; i < n; i++)
            answer.push_back(50);
        amount %= 50;
    }

    if(amount >= 10)
    {
        int n = amount / 10;
        for (int i = 0; i < n; i++)
            answer.push_back(10);
        amount %= 10;
    }

    if(amount >= 1)
    {
        int n = amount / 1;
        for (int i = 0; i < n; i++)
            answer.push_back(1);
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<int> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}


int main()
{
  print(solution(123)); //출력값 : 100 10 10 1 1 1
  print(solution(350)); //출력값 : 100 100 100 50
  
  return 0;
}