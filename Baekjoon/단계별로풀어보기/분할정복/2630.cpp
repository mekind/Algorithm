#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;
int arr[150][150];

pair<int, int> sol(int a, int b, int n) {
    int blue = 0, w = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[a + i][b + j])
                blue++;
            else
                w++;
        }
    }

    if (blue == 0) return {0, 1};
    if (w == 0) return {1, 0};
    blue = w = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            pair<int, int> now = sol(a + i * n / 2, b + j * n / 2, n / 2);
            blue += now.first;
            w += now.second;
        }
    }

    return {blue, w};
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
    pair<int, int> ans = sol(0, 0, N);

    cout << ans.second << "\n";
    cout << ans.first;

    return 0;
}