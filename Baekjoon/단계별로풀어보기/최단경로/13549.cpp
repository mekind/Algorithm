#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, K;
int ans[200010];

void sol() {
    for (int i = 0; i <= 200005; i++) {
        ans[i] = 100010;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({0, N});

    while (!pq.empty()) {
        int now = pq.top().second;
        int dis = -pq.top().first;

        pq.pop();
        if (ans[now] != 100010) continue;
        ans[now] = dis;
        if (now == K) break;

        if (now >= 1 && ans[now - 1] == 100010) pq.push({-dis - 1, now - 1});
        if (now < 100005 && ans[now + 1] == 100010) pq.push({-dis - 1, now + 1});

        if (now * 2 < 200005 && ans[now * 2] == 100010) pq.push({-dis, now * 2});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    sol();

    cout << ans[K];
    return 0;
}