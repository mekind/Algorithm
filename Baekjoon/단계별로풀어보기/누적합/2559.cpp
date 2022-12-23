#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, K;
int arr[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    int ans = arr[K];

    for (int i = 2; i + K - 1 <= N; i++) {
        ans = max(ans, arr[i + K - 1] - arr[i - 1]);
    }

    cout << ans;
}