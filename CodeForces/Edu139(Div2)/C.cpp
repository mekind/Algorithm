#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int testcase, m, ans;
int arr[200010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--)
    {
        cin >> m;
        // cout << "hit\n";
        memset(arr, 0, sizeof(arr));
        ans = 1;
        int startx = -1;
        int starty = -1;
        for (int j = 0; j < 2; j++)
        {
            string s;
            cin >> s;
            for (int i = 0; i < m; i++)
            {
                if (s[i] == 'W')
                    continue;
                else
                {
                    arr[i] += j + 1;
                }
            }
        }

        // cout << "hit\n";
        int pre = 0;
        for (int i = 0; i < m; i++)
        {
            // cout << i << "  hi  " << pre << " \n";
            if (arr[i] == 3 && pre == 0)
            {
                continue;
            }
            if (pre == 0)
            {
                pre = arr[i];
                continue;
            }
            if (arr[i] == 3)
            {
                pre = ((pre == 1) ? 2 : 1);
                continue;
            }
            if (arr[i] != pre)
            {
                ans = 0;
                break;
            }
            pre = arr[i];
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

/*
구현하는게 너무 느림

정확하게 구상하고 코딩하는게 더 빠를듯
*/