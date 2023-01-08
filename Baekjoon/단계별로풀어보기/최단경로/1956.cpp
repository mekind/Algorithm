#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int V, E;
vector<pair<int, int>> edge[510];
int dis[510][510];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dis[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        dis[a][b] = min(dis[a][b], c);
    }
    for (int mid = 1; mid <= V; mid++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                if (dis[s][mid] != INT_MAX && dis[mid][e] != INT_MAX) dis[s][e] = min(dis[s][e], dis[s][mid] + dis[mid][e]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= V; i++) {
        ans = min(ans, dis[i][i]);
    }

    if (ans == INT_MAX) {
        cout << "-1";
    } else
        cout << ans;

    return 0;
}