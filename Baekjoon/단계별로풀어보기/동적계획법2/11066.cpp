#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll dp[510][510];
ll pre[510];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--) {
        int k;
        cin >> k;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = 50000000;
                if (i == j) dp[i][j] = 0LL;
            }
        }
        memset(pre, 0, sizeof(pre));

        for (int i = 0; i < k; i++) {
            cin >> pre[i];

            if (i) pre[i] += pre[i - 1];
        }

        for (int dis = 1; dis < k; dis++) {
            for (int start = 0; start + dis < k; start++) {
                for (int mid = start; mid < start + dis; mid++) {
                    ll w = pre[start + dis];
                    if (start) w -= pre[start - 1];

                    dp[start][start + dis] = min(dp[start][start + dis], dp[start][mid] + dp[mid + 1][start + dis] + w);
                }
            }
        }

        cout << dp[0][k - 1] << "\n";
    }
    return 0;
}