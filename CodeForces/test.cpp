#include <iostream>

using namespace std;

int testcase, n, x, y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;

    while (testcase--)
    {
        cin >> n >> x >> y;
        if (x >= 1 && y >= 1)
        {
            cout << "-1\n";
            continue;
        }
        if (!x && !y)
        {
            cout << "-1";
            continue;
        }
        int cnt = 0;
        int now = 1;
        int xx = x ? x : y;
        if ((n - 1) % xx)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i < n; ++i)
        {
            if (cnt >= xx)
            {
                cout << i + 1 << " ";
                now = i + 1;
                cnt = 1;
            }
            else
            {
                cout << now << " ";
                cnt += 1;
            }
        }
        cout << endl;
    }
}