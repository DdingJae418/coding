#include <vector>

using namespace std;


vector<vector<int>> answer;
int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dir = 0;

bool check(int x, int y)
{
    if(x == N || x == -1 || y == N || y == -1) return false;
    if(answer[y][x] != 0) return false;

    return true;
}

pair<int, int> getNext(pair<int, int> pos)
{
    int nx = pos.first + dx[dir];
    int ny = pos.second + dy[dir];

    if (!check(nx, ny))
    {
        dir = (dir + 1) % 4;
        nx = pos.first + dx[dir];
        ny = pos.second + dy[dir];
    }

    return {nx, ny};
}

vector<vector<int>> solution(int n)
{   
    answer.resize(n, vector<int>(n, 0));
    N = n;
    pair<int, int> pos = {0,0};

    for (int i = 1; i <= n*n; i++)
    {
        answer[pos.second][pos.first] = i;
        pos = getNext(pos);
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iterator>
#include <iostream>

using namespace std;

void print(vector<vector<int>> vec)
{
  for(int i = 0 ; i < vec.size(); i++){
    copy(vec[i].begin(), vec[i].end(), std::ostream_iterator<int>(cout, " "));
    cout << endl;
  }
  
}

void init()
{
    dir = 0;
    answer.clear();
}

int main()
{
    print(solution(3));
    /*
    출력값 :
    1 2 3 
    8 9 4 
    7 6 5
    */

    init();
                    
    print(solution(4));
    /*
    출력값: 
    1 2 3 4 
    12 13 14 5 
    11 16 15 6 
    10 9 8 7
    */
  return 0;
}