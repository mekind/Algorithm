#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        int now = q.front();
        q.pop();
        q.push(now);
    }

    cout << q.front();

    return 0;
}