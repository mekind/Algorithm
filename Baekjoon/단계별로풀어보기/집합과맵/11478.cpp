#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
map<string, int> aaa;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;

    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            string now = s.substr(j, i);
            // cout << i << "  " << j << "  deee\n";
            // cout << now << "   ddd\n";
            aaa[now] = 1;
        }
    }

    cout << aaa.size();
}