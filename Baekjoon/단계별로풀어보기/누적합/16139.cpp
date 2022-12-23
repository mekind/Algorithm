#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int dp[30][200010];
string s;

void pre() {
    for (int idx = 0; idx < s.length(); ++idx) {
        int now = s[idx] - 'a';
        if (idx == 0) {
            dp[now][idx] = 1;
            continue;
        }
        for (int i = 0; i < 30; i++) {
            if (i == now) {
                dp[i][idx] = dp[i][idx - 1] + 1;
            } else
                dp[i][idx] = dp[i][idx - 1];
        }
    }
}

int sol(int now, int l, int r) {
    if (l) {
        return dp[now][r] - dp[now][l - 1];
    }
    return dp[now][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    pre();
    // for (int i = 0; i < s.length(); i++) {
    //     for (char j = 'a'; j <= 'z'; j++) {
    //         cout << j << " " << dp[j - 'a'][i] << " ";
    //     }
    //     cout << "\n";
    // }

    cin >> testcase;

    while (testcase--) {
        char target;
        int l, r;

        cin >> target >> l >> r;
        cout << sol(target - 'a', l, r) << "\n";
        ;
    }
}