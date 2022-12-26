#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
queue<int> q;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        if (!s.compare("push")) {
            int tmp;
            cin >> tmp;
            q.push(tmp);
        } else if (!s.compare("front")) {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
        } else if (!s.compare("back")) {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.back() << "\n";
        } else if (!s.compare("size")) {
            cout << q.size() << "\n";
        } else if (!s.compare("empty")) {
            cout << q.empty() << "\n";
        } else {
            if (q.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << q.front() << "\n";
            q.pop();
        }
    }

    return 0;
}