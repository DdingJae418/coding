#include <vector>
#include <iostream>

using namespace std;

vector<int> parents;
vector<int> rankData;

int charToInt(char c)
{
    return c - '0';
}

int find(int x)
{
    if (parents[x] == x)
        return x;

    parents[x] = find(parents[x]);

    return parents[x];
}

void unionSet(int x, int y)
{
    int root_x = find(x);
    int root_y = find(y);

    if (root_x != root_y)
    {
        if (rankData[root_x] < rankData[root_y])
        {
            parents[root_x] = root_y;
        }
        else if (rankData[root_y] < rankData[root_x])
        {
            parents[root_y] = root_x;
        }
        else
        {
            parents[root_y] = root_x;
            rankData[root_x]++;
        }
    }
}

vector<bool> solution(int k, vector<vector<char>> operations)
{
    parents.resize(k);
    rankData.resize(k, 0);

    for (int i = 0; i < k; i++)
    {
        parents[i] = i;
    }

    vector<bool> result;
    for (const auto& operation : operations)
    {
        int x = charToInt(operation[1]);
        int y = charToInt(operation[2]);

        if (operation[0] == 'u')
        {            
            unionSet(x, y);
        }
        else
        {
            result.push_back(find(x) == find(y));
        }
    }

    return result;
}

int main(void)
{
    vector<bool> answer = solution(3, {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}});

    for (bool a : answer)
        cout<<a<<' ';
}