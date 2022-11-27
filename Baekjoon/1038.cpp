#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int com[11][11];
int x;
vector<int> ans;

int get_com(int n, int r)
{
    if (r == n)
        return 1;
    if (r == 1)
        return n;
    if (n == 0 || r == 0 || n == 1)
        return 1;
    int &ret = com[n][r];
    if (ret != -1)
        return ret;
    if (com[r][n] != -1)
        return ret = com[r][n];
    return get_com(n - 1, r) + get_com(n - 1, r - 1);
}

int sol_len(int now, int len)
{
    if (len > 10)
        return -1;
    int next = get_com(10, len);
    if (now + next < x)
        return sol_len(now + next, len + 1);
    else
    {
        x -= now;
        return len;
    }
}

void sol(int now, int len, int num)
{
    for (int i = len - 1; i < num; ++i)
    {
        if (now + get_com(i, len - 1) < x)
        {
            now += get_com(i, len - 1);
            // cout << " now " << len << "   " << i << "  now " << now << "  d\n";
        }
        else
        {
            // cout << " now " << len << "   " << i << "  elsenow " << now << "  d\n";
            ans.push_back(i);
            if (now + get_com(i, len - 1) == x)
            {
                while (--len)
                {
                    ans.push_back(--i);
                }
                return;
            }

            sol(now, len - 1, i);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(com, -1, sizeof(com));
    cin >> x;
    x += 1;
    int len = sol_len(0, 1);
    if (len == -1)
    {
        cout << "-1\n";
        return 0;
    }

    sol(0, len, 10);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];
    cout << "\n";
    return 0;
}
