#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int H, W;
int arr[1010][1010];
int dp[1000][8];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }

    return 0;
}