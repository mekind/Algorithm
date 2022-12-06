#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int dx[2] = {1, -1};
int dy[2] = {-1, 1};
int X;

string sol(int a, int b)
{
    // cout << a << " dd \n";
    int dif = a - X;
    if (b % 2)
    {
        int x = 1;
        int y = b;
        for (int i = 0; i < dif; ++i)
        {
            x += dx[0];
            y += dy[0];
        }
        return to_string(x) + "/" + to_string(y);
    }
    else
    {
        int x = b;
        int y = 1;
        for (int i = 0; i < dif; ++i)
        {
            x += dx[1];
            y += dy[1];
        }
        return to_string(x) + "/" + to_string(y);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> X;
    int sum = 0;
    int idx = 0;
    for (int i = 1; i < 100000; ++i)
    {
        sum += i;
        if (sum >= X)
        {
            idx = i;
            break;
        }
    }
    cout << sol(sum, idx);
}