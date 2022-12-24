#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, arr[200010];
map<int, int> per;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];

        per[arr[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        int ans = 20000000;
        // int ans1 = 20000000, ans2 = 20000000;
        // if (i < N && arr[i] < N) ans1 = 1 + abs(per[arr[i] + 1] - i);
        // if (1 < i && arr[i] > 1) ans2 = 1 + abs(per[arr[i] - 1] - i);
        // ans = min(ans1, ans2);
        for (int j = 1; j < ans; j++) {
            if (i + j <= N) {
                int nans = abs(arr[i] - arr[i + j]) + j;
                ans = min(ans, nans);
            }
            if (i - j > 0) {
                int nans = abs(arr[i] - arr[i - j]) + j;
                ans = min(ans, nans);
            }
        }
        cout << ans << " ";
    }

    return 0;
}