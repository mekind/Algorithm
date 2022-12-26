#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    while (testcase--) {
        bool way = true;
        string s, tmp;
        int n;
        cin >> s;
        cin >> n;
        cin >> tmp;
        int now = -1;
        deque<int> dq;
        for (int i = 0; i < tmp.length(); i++) {
            if (tmp[i] >= '0' && tmp[i] <= '9') {
                if (now == -1) now = 0;
                now *= 10;
                now += tmp[i] - '0';
            } else if (now != -1) {
                dq.push_back(now);
                now = -1;
            }
        }
        bool err = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') {
                way = !way;
            } else {
                if (dq.empty()) {
                    cout << "error\n";
                    err = true;
                    break;
                }

                if (way)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (err) continue;

        cout << "[";
        if (way) {
            while (dq.size() > 1) {
                cout << dq.front() << ",";
                dq.pop_front();
            }
            if (!dq.empty()) cout << dq.front();
        } else {
            while (dq.size() > 1) {
                cout << dq.back() << ",";
                dq.pop_back();
            }
            if (!dq.empty()) cout << dq.back();
        }
        cout << "]\n";
    }

    return 0;
}