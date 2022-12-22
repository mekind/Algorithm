#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct Edge {
    int v;
    int d;
    int n;
};

int testcase;
int K;
vector<Edge> edge;
int next_num[2][5] = {{0, 4, 3, 1, 2}, {0, 3, 4, 2, 1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    int mx = 0, my = 0;
    int cnt0 = 0, cnt1 = 0;

    for (int i = 0; i < 6; i++) {
        Edge now;

        cin >> now.v >> now.d;
        if (i % 2) mx = max(mx, now.d);
        if (i % 2 == 0) my = max(my, now.d);
        if (i) {
            if (next_num[0][edge[i - 1].v] == now.v) now.n = 0;
            if (next_num[1][edge[i - 1].v] == now.v) now.n = 1;
        }
        edge.push_back(now);

        if (i == 5) {
            if (next_num[0][now.v] == edge[0].v) edge[0].n = 0;
            if (next_num[1][now.v] == edge[0].v) edge[0].n = 1;
        }
    }
    int ans = mx * my;
    for (int i = 0; i < 6; i++) {
        int bef = edge[(i + 5) % 6].n;
        int aft = edge[(i + 1) % 6].n;

        if (aft == bef && aft != edge[i].n) {
            ans -= edge[i].d * edge[(i + 5) % 6].d;
        }
    }

    cout << ans * K;
}