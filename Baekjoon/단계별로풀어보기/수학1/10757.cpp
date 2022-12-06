#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string s1, s2, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s1 >> s2;

    int l1 = s1.length();
    int l2 = s2.length();

    int flag = 0;
    for (int i = 0; i < max(l1, l2); ++i)
    {
        int now1, now2;

        if (i >= l1)
        {
            now1 = 0;
        }
        else
            now1 = s1[l1 - i - 1] - '0';
        if (i >= l2)
        {
            now2 = 0;
        }
        else
            now2 = s2[l2 - i - 1] - '0';
        int now = now1 + now2 + flag;

        flag = (int)now / 10;
        now %= 10;
        // cout << i << " " << now1 << "  " << now2 << "  dd\n";
        // cout << i << " " << now << "  " << flag << "  tt\n";

        ans.push_back('0' + now);
    }
    if (flag)
        ans.push_back('1');

    for (int i = ans.length() - 1; i >= 0; --i)
    {
        cout << ans[i];
    }
}