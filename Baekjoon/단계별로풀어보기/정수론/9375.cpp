#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--) {
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (mp.find(s2) != mp.end()) {
                mp[s2] += 1;
            } else
                mp[s2] = 1;
        }

        int ans = 1;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            ans *= (iter->second + 1);
        }
        cout << ans - 1 << "\n";
    }
}