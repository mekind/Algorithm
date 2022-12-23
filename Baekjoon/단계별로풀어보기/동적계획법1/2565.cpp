#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase, N;
int dp[550][550];
int connect1[550];
int connect2[550];

int sol(int x, int y) {
    if (x <= 0 || y <= 0) return 0;
    int &ret = dp[x][y];
    if (ret != -1) return ret;

    if (connect1[x] != 0 && connect1[x] <= y) {
        int ret1 = sol(x - 1, connect1[x] - 1) + 1;
        ret = max(ret, ret1);
    }
    if (connect2[y] != 0 && connect2[y] <= x) {
        int ret2 = sol(connect2[y] - 1, y - 1) + 1;
        ret = max(ret2, ret);
    }
    int ret3 = max(sol(x - 1, y), sol(x, y - 1));

    return ret = max(ret, ret3);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        int a, b;

        cin >> a >> b;

        connect1[a] = b;
        connect2[b] = a;
    }

    cout << N - sol(500, 500);
}
