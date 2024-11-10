#include <vector>
#include <queue>

using namespace std;

struct Compare
{
    bool operator()(const vector<double> item1, const vector<double> item2)
    {
        return item1[1]/item1[0] < item2[1]/item2[0];
    }
};

double solution(vector<vector<double>> items, double weight_limit)
{
    double answer = 0;
    priority_queue<vector<double>, vector<vector<double>>, Compare> pq;

    for (auto item : items)
        pq.push(item);

    while(weight_limit > 0)
    {
        auto next = pq.top();
        pq.pop();

        if(next[0] <= weight_limit)
        {
            answer += next[1];
            weight_limit -= next[0];
        }
        else
        {
            answer += (next[1]/next[0]) * weight_limit;
            weight_limit = 0;
        }
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

int main()
{
  cout << solution({{10, 19}, {7, 10}, {6, 10}}, 15) << endl; //출력값 : 27.3333
  cout << solution({{10, 60}, {20, 100}, {30, 120}}, 50) << endl; //출력값 : 240
  
  return 0;
}