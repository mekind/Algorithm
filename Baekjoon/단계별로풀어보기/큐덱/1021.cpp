#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
int arr[88];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> arr[i];
    }

    int now = 0;
    int ans = 0;
    while (now < M) {
        int ff = dq.front();
        int cnt = 0;
        while (arr[now] != ff) {
            cnt++;
            dq.pop_front();
            dq.push_back(ff);
            ff = dq.front();
        }
        now++;
        ans += min(abs((int)dq.size() - cnt), cnt);
        dq.pop_front();
    }

    cout << ans;

    return 0;
}