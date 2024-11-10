#include <vector>
#include <string>

using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> alphabet(30, 0);

    for (char c : s)
    {
        int idx = c -'a';
        alphabet[idx]++;
    }

    for (int i = 0; i < alphabet.size(); i++)
    {
        for (int j = 0; j < alphabet[i]; j++)
        {
            answer += (char)i + 'a';
        }
    }

    return answer;
}

//아래 코드는 테스트 코드 입니다.
#include <iostream>

using namespace std;

int main()
{
  cout << solution("hello") << endl; // 출력값 : ehllo
  cout << solution("algorithm") << endl; // 출력값 : aghilmort
  
  return 0;
}