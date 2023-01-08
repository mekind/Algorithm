#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, K;
int dp[200010];

bool is_range(int now) {
    if (now >= 0 && now <= 200000) return true;
    return false;
}

int sol() {
    queue<int> q;

    q.push(K);
    dp[K] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == N) break;

        if (now + 1 < 200000 && dp[now + 1] == -1) {
            dp[now + 1] = dp[now] + 1;
            q.push(now + 1);
        }
        if (now - 1 > 0 && dp[now - 1] == -1) {
            dp[now - 1] = dp[now] + 1;
            q.push(now - 1);
        }
        if (now % 2 == 0 && dp[now / 2] == -1) {
            dp[now / 2] = dp[now] + 1;
            q.push(now / 2);
        }
        if (dp[N] != -1) break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    memset(dp, -1, sizeof(dp));
    dp[K] = 0;
    sol();
    cout << dp[N] << "\n";

    int start = N;

    cout << start << " ";
    while (start != K) {
        if (is_range(start - 1) && dp[start - 1] == dp[start] - 1) {
            start -= 1;
            cout << start << " ";
            continue;
        }
        if (is_range(start + 1) && dp[start + 1] == dp[start] - 1) {
            start += 1;
            cout << start << " ";
            continue;
        }
        if (is_range(start * 2) && dp[start * 2] == dp[start] - 1) {
            start /= 2;
            cout << start << " ";
            continue;
        }
    }

    return 0;
}