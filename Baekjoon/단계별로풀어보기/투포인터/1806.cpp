#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> S;

    vector<ll> v;

    for (int i = 0; i < N; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(0);
    int l = 0, r = 0;

    ll sum = v[0];
    int ans = INT_MAX;
    while (l < N && r < N) {
        if (sum >= S) {
            ans = min(ans, r - l + 1);
            sum -= v[l];
            ++l;
        } else {
            r++;
            sum += v[r];
        }
    }

    if (ans == INT_MAX) {
        cout << "0";
    } else
        cout << ans;

    return 0;
}