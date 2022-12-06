#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

int arr[20][20];
int k, n, testcase;

int sol(int a, int b)
{
    int &ret = arr[a][b];
    if (ret != 0)
        return ret;

    for (int i = 1; i <= b; ++i)
        ret += sol(a - 1, i);

    // cout << a << " " << b << " hi" << ret << "\n";
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    for (int i = 0; i < 20; i++)
    {
        arr[0][i] = i;
    }

    while (testcase--)
    {
        cin >> k >> n;

        cout << sol(k, n) << "\n";
    }
}