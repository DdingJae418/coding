#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int countDifference(const vector<vector<char>>& vec1, const vector<vector<char>>& vec2, int startRow, int startCol)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (vec1[startRow + i][startCol + j] != vec2[i][j])
                count++;
        }
    }
    return count;
}

int main(void)
{
    int N = 0, M = 0;
    cin>>N>>M;

    vector<vector<char>> vec(N, vector<char>(M));
    for (auto& row : vec)
    {
        for (char& col : row)
        {
            cin>>col;
        }
    }

    vector<char> row_w = {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};
    vector<char> row_b = {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
    vector<vector<char>> chessBoard1 = {row_w, row_b, row_w, row_b, row_w, row_b, row_w, row_b};
    vector<vector<char>> chessBoard2 = {row_b, row_w, row_b, row_w, row_b, row_w, row_b, row_w};

    int result = numeric_limits<int>::max();

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            result = min(result, min(countDifference(vec, chessBoard1, i, j), countDifference(vec, chessBoard2, i, j)));
        }
    }

    cout<<result<<endl;

    return 0;
}