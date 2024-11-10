#include <vector>

using namespace std;

vector<vector<int>> answer;
vector<int> numarr;

void backtrack(int N, int sum, int start)
{
    if(sum == 10)
    {
        answer.push_back(numarr);
        return;
    }

    if(start + sum <= 10)
    {
        for (int i = start ; i <= N; i++)
        {
            numarr.push_back(i);
            backtrack(N, sum + i, i + 1);
            numarr.pop_back();
        }
    }
}

vector<vector<int>> solution(int N)
{
    backtrack(N, 0, 1);

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void init()
{
  answer.clear();
  numarr.clear();    
}

void print(vector<vector<int>> vec)
{
    
  for(int i = 0; i < vec.size(); i++ ){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
    
}

int main()
{
  print(solution(5));
  init();
  /*
    출력값
    1 2 3 4 
    1 4 5 
    2 3 5 
  */
  print(solution(2));
  init();
  /*
    출력값(없음)
  */  
  print(solution(7));
  /*
    출력값
    1 2 3 4 
    1 2 7 
    1 3 6 
    1 4 5 
    2 3 5 
    3 7 
    4 6 
  */
  return 0;
}