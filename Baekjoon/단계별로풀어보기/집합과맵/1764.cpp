#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
map<string, bool> tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;

        cin >> s;
        tmp[s] = true;
    }
    vector<string> v;
    for (int i = 0; i < M; i++) {
        string s;

        cin >> s;

        if (tmp.find(s) != tmp.end()) v.push_back(s);
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";

    for (string s : v) cout << s << "\n";
}