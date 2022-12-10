#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

bool arr[2500][2550];
int N;

void check_t(int x, int y, int xx)
{
    for (int i = x; i < x + xx; i++)
    {
        for (int j = y; j < y + xx; j++)
        {
            arr[i][j] = true;
        }
    }
}

void sol(int startx, int starty, int x)
{
    // cout << startx << " " << starty << "  " << x << " ddd\n";
    if (x <= 1)
        return;
    int xx = x / 3;
    for (int i = startx; i < startx + x; i += xx)
    {
        for (int j = starty; j < starty + x; j += xx)
        {
            if (i == startx + xx && j == starty + xx)
                check_t(i, j, xx);
            else
                sol(i, j, xx);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    sol(0, 0, 2187);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j])
                cout << " ";
            else
                cout << "*";
        }
        cout << "\n";
    }
}