#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            cnt++;
        } else {
            ans++;

            if (cnt) {
                ans += (cnt / 2);
                ans += (cnt % 2);
                cnt = 0;
            }
        }
    }

    if (cnt) {
        ans += (cnt / 2);
        ans += (cnt % 2);
        cnt = 0;
    }

    cout << ans;

    return 0;
}