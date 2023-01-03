#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> testcase;
    bool ans = false;
    while (testcase--) {
        int n;
        cin >> n;
        set<string> arr;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;

            if (tmp.length() == 1) {
                ans = true;
            }
            if (tmp.length() == 2) {
                if (tmp[0] == tmp[1]) {
                    ans = true;
                }
                string fd = "";
                fd.push_back(tmp[1]);
                fd.push_back(tmp[0]);
                if (arr.find(fd) != arr.end()) {
                    ans = true;
                }
            }
            if (tmp.length() == 3) {
                if (tmp[0] == tmp[2]) {
                    ans = true;
                }
                string fd = "";
                fd.push_back(tmp[2]);
                fd.push_back(tmp[1]);
                fd.push_back(tmp[0]);
                if (arr.find(fd) != arr.end()) {
                    ans = true;
                }
                fd = "";
                fd.push_back(tmp[2]);
                fd.push_back(tmp[1]);
                if (arr.find(fd) != arr.end()) {
                    ans = true;
                }

                arr.insert(tmp.substr(0, 2));
                arr.insert(tmp);
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}