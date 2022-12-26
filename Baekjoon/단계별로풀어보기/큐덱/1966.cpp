#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;

    while (testcase--) {
        cin >> N >> M;
        queue<pair<int, int>> q;
        vector<int> v;
        int ans = 1;
        for (int i = 0; i < N; i++) {
            int tmp;
            cin >> tmp;
            q.push({tmp, i});
            v.push_back(tmp);
        }

        sort(v.begin(), v.end());

        int idx = v.size() - 1;

        while (!(q.front().second == M && q.front().first == v[idx])) {
            int now = q.front().first;
            int now_idx = q.front().second;
            if (now == v[idx]) {
                ans++;
                idx--;
                q.pop();
            } else {
                q.pop();
                q.push({now, now_idx});
            }
        }
        cout << ans << "\n";
    }
    return 0;
}