#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int n, m, t;
int s, g, h;
pair<int, bool> ans[2020];

void sol(vector<vector<pair<int, int>>>& edge) {
    priority_queue<pair<int, pair<int, bool>>> pq;
    for (int i = 1; i <= n; i++) {
        ans[i] = {INT_MAX, false};
    }

    pq.push({0, {s, false}});

    while (!pq.empty()) {
        int now = pq.top().second.first;
        int dis = -pq.top().first;
        bool pos = pq.top().second.second;
        pq.pop();

        if (ans[now].first != INT_MAX) continue;

        ans[now] = {dis, pos};

        for (int i = 0; i < edge[now].size(); i++) {
            int next = edge[now][i].first;
            int ndis = edge[now][i].second;
            if (ans[next].first != INT_MAX) continue;
            if ((now == g && next == h) || (now == h && next == g)) {
                pq.push({-dis - ndis, {next, true}});
                continue;
            }
            pq.push({-dis - ndis, {next, pos}});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        vector<vector<pair<int, int>>> edge(n + 1, vector<pair<int, int>>());

        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            edge[a].push_back({b, d});
            edge[b].push_back({a, d});
        }
        sol(edge);
        vector<int> cd;
        for (int i = 0; i < t; i++) {
            int tmp;
            cin >> tmp;
            cd.push_back(tmp);
        }
        sort(cd.begin(), cd.end());

        for (int now : cd) {
            if (ans[now].second) {
                cout << now << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}