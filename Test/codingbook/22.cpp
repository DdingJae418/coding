#include <string>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    if(phone_book.size() == 1)
        return true;

    // sort phone book
    sort(phone_book.begin(), phone_book.end());

    // 접두어 같은지 확인
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        // 뒷 번호 길이가 더 짧은 경우 제외
        if(phone_book[i].length() > phone_book[i+1].length())
            continue;
        else
        {
            int len = phone_book[i].length();
            if(phone_book[i] == phone_book[i+1].substr(0, len))
            {
                answer = false;
                break;
            }
        }
    }

    return answer;
}
