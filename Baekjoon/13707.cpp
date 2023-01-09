#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K;
int dp[5010][5010];
int sum[5010];

void ppp() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        dp[0][i] = 1;
        sum[i] = 1;
    }

    // ppp();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j == 1) {
                dp[i][j] = 1;
            } else
                dp[i][j] = sum[j - 1];
            sum[j] += dp[i][j];
            sum[j] %= 1000000000;

            // cout << "now" << i << " " << j << "   " << dp[i][j] << "   sum  " << sum[j] << "\n";
        }
    }

    cout << dp[N][K];

    return 0;
}