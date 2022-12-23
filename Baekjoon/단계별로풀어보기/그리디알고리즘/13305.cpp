#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
ll N, dis[100010], cost[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (ll i = 0; i < N - 1; i++) {
        cin >> dis[i];
    }

    for (ll i = 0; i < N; i++) {
        cin >> cost[i];
    }
    ll ans = 0;

    for (int i = 0; i <= N - 1; i++) {
        ll nowc = cost[i];
        ll nowd = dis[i];
        for (int j = i + 1; j <= N - 1; j++) {
            if (cost[j] < nowc || j == N - 1) {
                ans += nowd * nowc;
                i = j - 1;
                break;
            }
            nowd += dis[j];
        }
    }
    cout << ans;
}