#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll N, M;

pair<ll, ll> sol(ll n) {
    ll cnt2 = 0;
    ll cnt5 = 0;

    ll start = 2LL;
    while (start <= n) {
        cnt2 += (n / start);
        start *= 2;
    }

    start = 5LL;
    while (start <= n) {
        cnt5 += (n / start);
        start *= 5;
    }

    return {cnt2, cnt5};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    pair<ll, ll> tmp1 = sol(N);
    pair<ll, ll> tmp2 = sol(M);
    pair<ll, ll> tmp3 = sol(N - M);

    ll aa = tmp1.first - tmp2.first - tmp3.first;
    ll bb = tmp1.second - tmp2.second - tmp3.second;

    cout << min(aa, bb);
}