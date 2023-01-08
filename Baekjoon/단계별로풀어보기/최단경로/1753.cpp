#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int V, E, K;
vector<pair<int, int>> edge[20010];
int ans[20010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> K;
    for (int i = 0; i <= V; i++) {
        ans[i] = 30000000;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;

        cin >> u >> v >> w;

        edge[u].push_back({v, w});
    }

    priority_queue<pair<int, int>> pq;

    pq.push({0, K});

    while (!pq.empty()) {
        int dis = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (ans[now] != 30000000) continue;

        ans[now] = dis;

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int ndis = edge[now][i].second;
            if (ans[next] != 30000000) continue;
            pq.push({-(ndis + dis), next});
        }
    }

    for (int i = 1; i <= V; i++) {
        if (ans[i] == 30000000)
            cout << "INF\n";
        else
            cout << ans[i] << "\n";
    }

    return 0;
}