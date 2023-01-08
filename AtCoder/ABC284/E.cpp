#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M, K;

vector<int> edge[200010];
bool visited[200010];

void sol(int now) {
    K++;
    if (K >= 1000000) return;
    for (int i = 0; i < edge[now].size(); i++) {
        int next = edge[now][i];
        if (!visited[next]) {
            visited[next] = true;
            sol(next);
            if (K >= 1000000) break;
            visited[next] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;

        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    visited[1] = true;
    sol(1);

    cout << K;

    return 0;
}