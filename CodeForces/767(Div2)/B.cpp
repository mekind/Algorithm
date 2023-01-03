#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int l, r, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--) {
        cin >> l >> r >> k;

        if (l == r && l == 1) {
            cout << "NO\n";
            continue;
        }

        if (r - l == k) {
            cout << "YES\n";
            continue;
        }

        int start = -1, des = -1;
        for (int i = l; i <= r; i++) {
            if (i % 2) {
                start = i / 2;
                break;
            }
        }
        for (int i = r; i >= l; i--) {
            if (i % 2) {
                des = i / 2;
                break;
            }
        }
        int odd = 0;
        if (start != -1) odd = des - start + 1;

        if (odd <= k) {
            cout << "YES\n";
        } else
            cout << "NO\n";
    }

    return 0;
}