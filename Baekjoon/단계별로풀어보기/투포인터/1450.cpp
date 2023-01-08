#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll N, C;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;

    vector<ll> v;

    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;

        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        ll sum = v[i];
        int l = 0, r = 0;
        ll sum += v[0];
        while (l <= r && r <= i) {
            if (sum <= C) {
            }
        }
    }

    cout << ans;

    return 0;
}