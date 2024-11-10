#include <vector>
#include <string>

using namespace std;

int idx;

bool compare(const string &s1, const string &s2)
{
    if(s1[idx] == s2[idx])
        return s1 < s2;
    else    
        return s1.substr(idx) < s2.substr(idx);
}

vector<string> solution(vector<string> strings, int n)
{
    idx = n;
    sort(strings.begin(), strings.end(), compare);

    return strings;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>
#include <iterator>

using namespace std;

void print(vector<string> vec)
{
  copy(vec.begin(), vec.end(), std::ostream_iterator<string>(cout, " "));
  cout << endl;
}

int main()
{
  print(solution({"sun", "bed", "car"}, 1)); //출력값 : car bed sun
  print(solution({"abce", "abcd", "cdx"}, 2));  // 출력값 : abcd abce cdx

  return 0;
}