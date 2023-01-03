#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

int testcase;
ll N, K;

ll sol(ll n, ll p) {
    if (p == 1LL) return n;
    ll nn = (n * n) % MOD;
    if (p % 2) {
        return (n * sol(nn, p / 2)) % MOD;
    }
    return sol(nn, p / 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    ll ans = 1LL;
    for (ll i = N - K + 1LL; i <= N; i++) {
        ans *= i;
        ans %= MOD;
    }
    ll ans2 = 1LL;
    for (ll i = 1LL; i <= K; i++) {
        ans2 *= i;
        ans2 %= MOD;
    }

    ans2 = sol(ans2, MOD - 2LL);

    cout << (ans * ans2) % MOD;

    return 0;
}