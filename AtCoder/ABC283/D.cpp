#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
set<int> box;
vector<vector<int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;
    bool ans = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            vector<int> n;
            // n.push_back(0);
            v.push_back(n);
        } else if (s[i] == ')') {
            if (v.empty()) continue;
            for (int j = 0; j < v.back().size(); j++) {
                box.erase(v.back()[j]);
            }
            v.pop_back();

        } else {
            int now = s[i] - 'a';
            if (box.find(now) == box.end()) {
                box.insert(now);
                if (!v.empty()) v.back().push_back(now);
            } else {
                {
                    ans = false;
                    break;
                }
            }
        }
    }

    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
