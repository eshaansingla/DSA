#include <iostream>
using namespace std;
int main()
{
    int r;
    int c;
    cout << "Enter rows:";
    cin >> r;
    cout << "Enter columns:";
    cin >> c;
    int a[r][c];
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] = k + 1;
            k++;
        }
    }
    /*
    1 2 3 4
    5 6 7 8
    0 1 2 3
    9 8 7 6
    */
    int minrow = 0;
    int maxrow = r - 1;
    int minc = 0;
    int maxc = c - 1;
    int cnt = 0;
    while (cnt < r * c)
    {
        for (int j = minc; j <= maxc; j++)
        {
            if(cnt<r*c){
            cout << a[minrow][j] << "  ";
            cnt++;
        }
        }
        minrow++;
        for (int i = minrow; i <= maxrow; i++)
        {
            if(cnt<r*c){
            cout << a[i][maxc] << "  ";
            cnt++;
            }
        }
        maxc--;
        for (int j = maxc; j >= minc; j--)
        {
            if(cnt<r*c){
            cout << a[maxrow][j] << "  ";
            cnt++;
        }
        }
        maxrow--;
        for (int i = maxrow; i >= minrow; i--)
        {
            if(cnt<r*c){
            cout << a[i][minc] << "  ";
            cnt++;
        }
        }
        minc++;
    }
}