#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, bomb;
    cin >> s >> bomb;

    string ans;
    vector<int> arr;

    int idx = 0;
    int nidx = 0;
    for (int i = 0; i < s.length(); i++) {
        ans.push_back(s[i]);

        if (s[i] == bomb[idx]) {
            arr.push_back(++idx);
        } else if (s[i] == bomb[0]) {
            idx = 1;
            arr.push_back(idx);
        } else {
            arr.push_back(0);
            idx = 0;
        }

        if (idx == bomb.length()) {
            for (int j = 0; j < bomb.length(); j++) {
                ans.pop_back();
                arr.pop_back();
            }
            if (ans.empty()) {
                idx = 0;
            } else {
                idx = arr.back();
            }
        }
    }

    if (ans.empty()) {
        cout << "FRULA\n";
    } else
        cout << ans;

    return 0;
}