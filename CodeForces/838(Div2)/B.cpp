#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int testcase;
ll arr[100010];

ll sol(ll a)
{
    ll cnt = 0;
    ll start = 1LL;
    while (start < a)
    {
        start <<= 1;
        cnt++;
    }

    return start - a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--)
    {
        int n;
        vector<pair<ll, ll>> ans;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            ll tmp = sol(arr[i]);
            if (tmp)
                ans.push_back({i, tmp});
        }

        cout << ans.size() << "\n";
        for (pair<ll, ll> now : ans)
        {
            cout << now.first << " " << now.second << "\n";
        }
    }
}