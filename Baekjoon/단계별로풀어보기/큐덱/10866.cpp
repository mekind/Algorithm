#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    deque<int> dq;
    while (N--) {
        string s;

        cin >> s;
        if (!s.compare("push_front")) {
            int tmp;
            cin >> tmp;
            dq.push_front(tmp);
        } else if (!s.compare("push_back")) {
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        } else if (!s.compare("pop_front")) {
            if (dq.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << dq.front() << "\n";
            dq.pop_front();
        } else if (!s.compare("pop_back")) {
            if (dq.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << dq.back() << "\n";
            dq.pop_back();
        } else if (!s.compare("size")) {
            cout << dq.size() << "\n";
        } else if (!s.compare("empty")) {
            cout << dq.empty() << "\n";
        } else if (!s.compare("front")) {
            if (dq.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << dq.front() << "\n";
        } else {
            if (dq.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << dq.back() << "\n";
        }
    }

    return 0;
}