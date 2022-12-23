#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M, K;
bool board[2010][2010];
int arr[2][2010][2010];  // 0 : start with black

void pre() {
    // start with black

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[0][i][j] = arr[0][i - 1][j] + arr[0][i][j - 1] - arr[0][i - 1][j - 1];
            if ((i - j) % 2 == 0 && !board[i][j]) arr[0][i][j] += 1;
            if ((i - j) % 2 && board[i][j]) arr[0][i][j] += 1;
        }
    }

    // start with white

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            arr[1][i][j] = arr[1][i - 1][j] + arr[1][i][j - 1] - arr[1][i - 1][j - 1];
            if ((i - j) % 2 && !board[i][j]) arr[1][i][j] += 1;
            if ((i - j) % 2 == 0 && board[i][j]) arr[1][i][j] += 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == 'B')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    pre();
    int ans = 4000010;

    for (int i = K; i <= N; i++) {
        for (int j = K; j <= M; j++) {
            int sb = arr[0][i][j] - arr[0][i - K][j] - arr[0][i][j - K] + arr[0][i - K][j - K];
            ans = min(ans, sb);
            int sw = arr[1][i][j] - arr[1][i - K][j] - arr[1][i][j - K] + arr[1][i - K][j - K];
            ans = min(ans, sw);
        }
    }

    cout << ans;
}