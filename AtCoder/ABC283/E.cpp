#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int H, W;
int arr[3][1010][1010];
int dp[1010][3];
int pre[1010][3];

bool pos(int a, int b) {
    if (a < 0 || a >= H || b < 0 || b >= W) return false;
    return true;
}

bool checking(int now_change, int pre_change, int now) {
    now -= 1;
    for (int i = 0; i < W; i++) {
        bool now_check = true;
        int now_num = arr[pre_change][now][i];
        for (int j = 0; j < 4; j++) {
            int nowx = i + dx[j];
            int nowy = now + dy[j];

            if (!pos(nowx, nowy)) continue;
            int next;

            if (nowy == now - 1)
                next = arr[pre[now - 1][pre_change]][nowy][nowx];
            else if (nowy == now)
                next = arr[pre_change][nowy][nowx];
            else
                next = arr[now_change][nowy][nowx];

            if (now_num == next) {
                now_check = false;
                break;
            }
        }
        if (now_check) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[0][i][j];
            arr[1][i][j] = 1 - arr[0][i][j];
        }
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < H; i++) {
        dp[i][0] = 1010;
        dp[i][1] = 1010;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i - 1][k] != 1010 && checking(j, k, i)) {
                    if (dp[i - 1][k] + j < dp[i][j]) {
                        dp[i][j] = dp[i - 1][k] + j;
                        pre[i][j] = k;
                    }
                }
            }
        }
        if (dp[i][0] == 1010 && dp[i][1] == 1010) {
            cout << "-1";
            return 0;
        }
    }

    cout << min(dp[H - 1][0], dp[H - 1][1]);

    return 0;
}