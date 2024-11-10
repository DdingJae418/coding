#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> tmap;
    unordered_set<int> s;

    // 토핑 개수 확인
    for (int t : topping)
        tmap[t]++;

    for (int i = 0; i < topping.size(); i++)
    {
        s.insert(topping[i]);

        tmap[topping[i]]--;
        if(tmap[topping[i]] == 0) tmap.erase(topping[i]);

        if(s.size() == tmap.size()) answer++;
    }
    return answer;
}