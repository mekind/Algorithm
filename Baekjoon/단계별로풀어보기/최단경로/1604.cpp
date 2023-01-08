#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, E, V1, V2;
vector<pair<int, ll>> edge[810];
ll dist[810];

int sol(int s, int e) {
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= N; i++) {
        dist[i] = LLONG_MAX;
    }

    pq.push({0, s});

    while (!pq.empty()) {
        ll dis = -pq.top().first;
        int now = pq.top().second;

        pq.pop();

        if (dist[now] != LLONG_MAX) continue;

        dist[now] = dis;

        if (now == e) break;

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            ll ndis = edge[now][i].second;
            if (dist[next] != LLONG_MAX) continue;
            pq.push({-dis - ndis, next});
        }
    }
    if (dist[e] == LLONG_MAX) return INT_MAX;
    return dist[e];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    cin >> V1 >> V2;

    ll tov1 = sol(1, V1);
    ll tov2 = sol(1, V2);
    ll v2tov1 = sol(V2, V1);
    ll v1tov2 = sol(V1, V2);
    ll v1ton = sol(V1, N);
    ll v2ton = sol(V2, N);

    ll ans = min(tov1 + v1tov2 + v2ton, tov2 + v2tov1 + v1ton);
    if (ans >= INT_MAX) {
        cout << "-1";
    } else
        cout << ans;

    return 0;
}