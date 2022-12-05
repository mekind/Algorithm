#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int arr[25];
int ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    for (int i = 0; i < 26; i++)
    {
        if (i <= 14)
        {
            int tmp = i / 3;
            arr[i] = tmp + 3;
        }

        if (14 < i && i < 19)
        {
            arr[i] = 8;
        }

        if (18 < i && i < 22)
        {
            arr[i] = 9;
        }
        if (21 < i && i < 26)
        {
            arr[i] = 10;
        }
    }

    for (int i = 0; i < s.size(); ++i)
    {
        int now = s[i] - 'A';
        ans += arr[now];
    }

    cout << ans;
}