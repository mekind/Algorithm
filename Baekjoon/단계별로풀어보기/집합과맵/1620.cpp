#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
int N, M;
map<string, string> ss;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        ss[s] = to_string(i);
        ss[to_string(i)] = s;
        // cout << ss.find(s)->second << "   dfadfads\n";
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        // cout << "  hihi\n";
        cout << ss.find(s)->second << "\n";
    }
}
