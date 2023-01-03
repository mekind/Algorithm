#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
int arr[2200][2200];
int ans[3];

void sol(int x, int y, int n) {
    int cnt[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[x + i][y + j] == -1) {
                cnt[0]++;
            } else if (arr[x + i][y + j] == 0) {
                cnt[1]++;
            } else {
                cnt[2]++;
            }
        }
    }

    if (!cnt[1] && !cnt[2]) {
        ans[0]++;
        return;
    }
    if (!cnt[2] && !cnt[0]) {
        ans[1]++;
        return;
    }
    if (!cnt[0] && !cnt[1]) {
        ans[2]++;
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sol(x + n / 3 * i, y + n / 3 * j, n / 3);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    sol(0, 0, N);

    for (int i = 0; i < 3; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}