#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, C;
int arr[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int l = 0, r = 1000000000;
    int ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 1;
        int pre = 0;
        for (int i = 1; i < N; i++) {
            if (arr[i] - arr[pre] >= mid) {
                pre = i;
                cnt++;
                continue;
            }
        }

        if (cnt >= C) {
            l = mid + 1;
            ans = max(mid, ans);
        } else
            r = mid - 1;
    }

    cout << ans;

    return 0;
}