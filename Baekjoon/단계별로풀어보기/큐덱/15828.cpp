#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    queue<int> q;
    while (1) {
        int tmp;
        cin >> tmp;

        if (tmp == -1) break;

        if (tmp && q.size() < N)
            q.push(tmp);
        else if (tmp) {
            continue;
        } else
            q.pop();
    }

    if (q.empty()) {
        cout << "empty";
        return 0;
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}