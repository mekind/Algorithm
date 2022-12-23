#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
bool ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> testcase;

    while (testcase--) {
        string s;
        cin >> s;
        ans = true;
        vector<int> v;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')' && v.empty()) {
                ans = false;
            } else if (s[i] == ')') {
                v.pop_back();
            } else
                v.push_back(1);
        }
        if (!v.empty()) ans = false;
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}