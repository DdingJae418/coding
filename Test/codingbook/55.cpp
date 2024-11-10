#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const int &a, const int &b) { return a > b; }
};

vector<int> solution(vector<int> arr1, vector<int> arr2)
{
    vector<int> answer;

    priority_queue<int, vector<int>, Compare> pq(arr1.begin(), arr1.end());

    for (int i : arr2)
        pq.push(i);

    while(!pq.empty())
    {
        answer.push_back(pq.top());
        pq.pop();
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
  print(solution({1, 3, 5}, {2, 4, 6})); // 출력값 : 1 2 3 4 5 6
  print(solution({1, 2, 3}, {4, 5, 6})); // 출력값 : 1 2 3 4 5 6
  
  return 0;
}