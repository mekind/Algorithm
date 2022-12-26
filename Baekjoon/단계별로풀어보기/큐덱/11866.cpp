#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";

    while (!q.empty()) {
        for (int i = 0; i < K - 1; i++) {
            int now = q.front();
            q.pop();
            q.push(now);
        }
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }

    cout << ">";

    return 0;
}