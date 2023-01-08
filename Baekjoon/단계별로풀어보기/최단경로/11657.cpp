#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
bool pos;
ll ans[510];
vector<pair<int, ll>> edge[510];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back({b, c});
    }
    pos = true;

    for (int i = 1; i <= N; i++) {
        ans[i] = INT_MAX;
    }
    ans[1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < edge[j].size(); k++) {
                int now = j;
                if (ans[now] != INT_MAX) {
                    int next = edge[j][k].first;
                    if (i == N - 1 && ans[next] > edge[j][k].second + ans[now]) pos = false;
                    ans[next] = min(ans[next], edge[j][k].second + ans[now]);
                }
            }
        }
    }

    if (pos) {
        for (int i = 2; i <= N; i++) {
            if (ans[i] == INT_MAX) {
                cout << "-1\n";
            } else
                cout << ans[i] << "\n";
        }

    } else {
        cout << "-1\n";
    }

    return 0;
}