#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    int left = min(a, b) - 1;
    int right = max(a, b) - 1;

    while((right/2) != (left/2))
    {
        answer++;

        left = left/2;
        right = right/2;
    }

    return answer;
}