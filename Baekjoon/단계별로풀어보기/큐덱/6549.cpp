#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll n;

ll sol(vector<ll>& v, ll start, ll des) {
    if (start == des) return v[start];
    ll mid = (start + des) / 2;

    ll ret0 = max(sol(v, start, mid), sol(v, mid + 1, des));
    ll ret = 0LL;

    ll left = mid, right = mid;

    ll max_h = v[mid];
    while (left >= start && right <= des) {
        max_h = min(v[left], max_h);
        max_h = min(v[right], max_h);
        ret = max(ret, (right - left + 1) * max_h);
        if (left == start) {
            right++;
            continue;
        }
        if (right == des) {
            left--;
            continue;
        }
        if (v[left - 1] <= v[right + 1])
            right++;
        else
            left--;
    }
    return max(ret0, ret);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        cin >> n;

        if (!n) break;
        vector<ll> v;
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        cout << sol(v, 0, n - 1) << "\n";
    }

    return 0;
}