#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b;

    cin >> a >> b;

    ll ans = 1LL;

    for (ll i = 0; i < b; i++) {
        ans *= a;
    }

    cout << ans;

    return 0;
}
