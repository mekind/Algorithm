#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll N, C;
vector<ll> g1, g2;
vector<ll> sum1(1, 0), sum2(1, 0);

void sol1(int idx, ll now) {
    if (idx >= N / 2) return;

    sol1(idx + 1, now);
    ll next = now + g1[idx];
    if (next <= C) {
        sol1(idx + 1, next);
        sum1.push_back(next);
    }
}

void sol2(int idx, ll now) {
    if (idx >= N / 2) return;

    sol2(idx + 1, now);
    ll next = now + g2[idx];
    if (next <= C) {
        sol2(idx + 1, next);

        sum2.push_back(next);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        ll tmp;

        cin >> tmp;

        if (i < N / 2)
            g1.push_back(tmp);
        else
            g2.push_back(tmp);
    }

    sol1(0, 0);
    sol2(0, 0);

    sort(sum2.begin(), sum2.end());

    ll ans = 0LL;
    for (int i = 0; i < sum1.size(); i++) {
        ll now = C - sum1[i];

        ll cnt = upper_bound(sum2.begin(), sum2.end(), now) - sum2.begin();
        ans += cnt;
    }

    cout << ans;
    return 0;
}