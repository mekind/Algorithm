#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
map<string, bool> ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ss[s] = true;
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        string m;

        cin >> m;
        if (ss.find(m) != ss.end()) ans++;
    }

    cout << ans;
}