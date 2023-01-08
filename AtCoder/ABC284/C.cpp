#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
int parent[110];

int my_find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = my_find(parent[a]);
}

void my_uni(int a, int b) {
    int aa = my_find(a);
    int bb = my_find(b);
    if (aa == bb) return;
    if (aa < bb) parent[bb] = aa;
    if (aa > bb) parent[aa] = bb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v;

        cin >> u >> v;
        my_uni(u, v);
    }

    set<int> ans;
    for (int i = 1; i <= N; i++) {
        ans.insert(my_find(i));
    }

    cout << ans.size();

    return 0;
}