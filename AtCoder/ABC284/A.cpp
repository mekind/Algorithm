#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;

    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << v[i] << "\n";
    }

    return 0;
}