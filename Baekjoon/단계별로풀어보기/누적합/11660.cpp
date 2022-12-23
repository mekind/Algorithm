#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;
ll arr[1030][1030];
// ll dp[1030][1030];

void pre() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
            // cout << arr[i][j] << " dd\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    pre();
    for (int i = 0; i < M; i++) {
        int a, b, aa, bb;

        cin >> a >> b >> aa >> bb;

        // cout << dp[aa][bb] - dp[a][bb] - dp[aa][b] + dp[a][b] << "\n";
        cout << arr[aa][bb] - arr[a - 1][bb] - arr[aa][b - 1] + arr[a - 1][b - 1] << "\n";
    }
}