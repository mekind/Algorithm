#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int n, x;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int now = v[i];
        int idx = lower_bound(v.begin(), v.end(), x - v[i]) - v.begin();

        if (idx >= n || v[idx] != x - v[i]) continue;

        int idx2 = upper_bound(v.begin(), v.end(), x - v[i]) - v.begin();

        ans += idx2 - idx;
    }
    cout << ans / 2;

    return 0;
}