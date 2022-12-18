#include <bits/stdc++.h>
#define MOD 998244353LL
using namespace std;
typedef long long ll;

int testcase;
ll e[200010];

void pre()
{
    e[0] = 1LL;
    for (int i = 1; i < 200005; ++i)
    {
        e[i] = (e[i - 1] << 1) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    cin >> testcase;

    while (testcase--)
    {
        int n;
        string s;
        cin >> n >> s;
        ll ans = 0LL;
        int last1 = -1;
        int last0 = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] - '0')
                last1 = i;
            else
                last0 = i;

            if (last0 == -1)
            {
                ans += e[last1];
            }
            else if (last1 == -1)
            {
                ans += e[last0];
            }
            else
            {
                ans += e[max(last0, last1) - min(last0, last1) - 1];
            }

            ans %= MOD;
            // cout << ans << "  " << i << "dddd\n";
        }
        cout << ans << "\n";
    }
}
