#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        string s;
        getline(cin, s);

        if (s[0] == '.') break;

        vector<char> v;
        bool ans = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') break;
            if (s[i] == '(' || s[i] == '[') {
                v.push_back(s[i]);
            }
            if ((s[i] == ')' || s[i] == ']') && v.empty()) {
                ans = true;
                break;
            }
            if (s[i] == ']') {
                char last = v.back();
                v.pop_back();
                if (last != '[') {
                    ans = true;
                    break;
                }
            }
            if (s[i] == ')') {
                char last = v.back();
                v.pop_back();
                if (last != '(') {
                    ans = true;
                    break;
                }
            }
        }

        if (!v.empty()) ans = true;

        if (ans)
            cout << "no\n";
        else
            cout << "yes\n";
    }
    return 0;
}