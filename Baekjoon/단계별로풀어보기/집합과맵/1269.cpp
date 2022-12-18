#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
int arr[200010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        int idx = lower_bound(arr, arr + N, tmp) - arr;

        if (0 <= idx && idx < N && arr[idx] == tmp) ans++;
    }

    cout << N + M - 2 * ans;
}