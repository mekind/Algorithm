#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
int s, e;
vector<pair<int, ll>> edge[100010];
vector<pair<int, ll>> edge2[100010];
ll d[100010];

void sol() {
    priority_queue<pair<ll, int>> pq;

    pq.push({0, s});

    while (!pq.empty()) {
        int now = pq.top().second;
        ll dis = -pq.top().first;
        pq.pop();

        if (d[now] != -1) continue;
        d[now] = dis;
        if (now == e) break;

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int ndis = edge[now][i].second;

            if (d[next] != -1) continue;
            pq.push({-dis - ndis, next});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(d, -1, sizeof(d));
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        edge[a].push_back({b, c});
        edge2[b].push_back({a, c});
    }
    cin >> s >> e;

    sol();
    cout << d[e] << "\n";

    vector<int> v(1, e);

    while (v.back() != s) {
        int now = v.back();
        for (int i = 0; i < edge2[now].size(); i++) {
            int next = edge2[now][i].first;
            int dis = edge2[now][i].second;

            if (d[now] - dis == d[next]) {
                v.push_back(next);
                break;
            }
        }
    }
    int ans = v.size();
    cout << ans << "\n";
    for (int i = ans - 1; i >= 0; i--) {
        cout << v[i] << " ";
    }

    return 0;
}