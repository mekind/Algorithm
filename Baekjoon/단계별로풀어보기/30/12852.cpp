#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
int dp[1000010];

int sol(int now) {
    int &ret = dp[now];
    if (ret != -1) return ret;
    ret = 10000000;
    if (now % 3 == 0) ret = min(ret, sol(now / 3) + 1);

    if (now % 2 == 0) ret = min(ret, sol(now / 2) + 1);

    return ret = min(ret, sol(now - 1) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, -1, sizeof(dp));
    dp[1] = 0;
    sol(N);

    cout << dp[N] << "\n";

    int start = N;
    while (start != 1) {
        cout << start << " ";
        int next = 0;
        if (start % 3 == 0 && dp[start / 3] + 1 == dp[start]) next = start / 3;
        if (start % 2 == 0 && dp[start / 2] + 1 == dp[start]) next = start / 2;
        if (dp[start - 1] + 1 == dp[start]) next = start - 1;

        start = next;
    }
    cout << "1";

    return 0;
}