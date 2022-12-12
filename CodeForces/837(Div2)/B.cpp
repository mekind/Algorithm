#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int testcase;
ll arr[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    while (testcase--)
    {
        ll n, m;
        ll ans = 0LL;
        cin >> n >> m;

        memset(arr, 0, sizeof(arr));

        for (ll i = 0LL; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            ll sm = min(a, b);
            ll mx = max(a, b);
            if (arr[sm] == 0LL)
                arr[sm] = mx;
            else
                arr[sm] = min(arr[sm], mx);
        }
        ll lim = n + 1;
        for (int i = n; i > 0; i--)
        {
            if (arr[i] == 0)
                arr[i] = n + 1;
            arr[i] = min(lim, arr[i]);
            lim = min(lim, arr[i]);
        }

        for (ll i = 1LL; i <= n; i++)
        {
            ans += arr[i] - i;

            // cout << i << "  " << ans << "  sss\n";
        }
        cout << ans << "\n";
    }
}