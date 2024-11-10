#include <iostream>

using namespace std;

class BoundCheck2DIntArray
{
private:
    int** arr;
    int row, col;
public:
    BoundCheck2DIntArray(int r, int c) : row(r), col(c)
    {
        arr = new int*[r];
        for (int i = 0; i < r; i++)
            arr[i] = new int[c];
    }
    int* operator[](int idx)
    {
        if(idx < 0 || idx >= row)
        {
            cout<<"Index Out of Range"<<endl;
            exit(1);
        }

        return arr[idx];
    }
    ~BoundCheck2DIntArray()
    {
        for (int i = 0; i < row; i++)
            delete[] arr[i];

        delete[] arr;
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(3,4);

    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
            cout<<arr2d[n][m]<<' ';
        cout<<endl;
    }

    return 0;
}