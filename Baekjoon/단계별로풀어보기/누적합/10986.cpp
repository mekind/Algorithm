#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
int arr[1000010];
ll rest[1010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        arr[i] %= M;
        rest[arr[i]]++;
    }
    ll ans = rest[0];
    for (int i = 0; i < M; i++) {
        ans += rest[i] * (rest[i] - 1LL) / 2LL;
    }

    cout << ans;
}