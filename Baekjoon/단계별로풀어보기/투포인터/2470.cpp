#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int l = 0, r = N - 1;
    ll ans = INT_MAX;
    int ansl, ansr;

    while (l < r) {
        ll now = v[l] + v[r];

        if (abs(now) < ans) {
            ans = abs(now);
            ansl = v[l];
            ansr = v[r];
        }
        if (now > 0) r--;
        if (now < 0) l++;
        if (now == 0) break;
    }

    cout << ansl << " " << ansr;

    return 0;
}