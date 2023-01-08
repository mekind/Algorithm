#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

deque<char> rev, ori;
int N;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int NN = 2 * N;
    cin >> s;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        rev.push_back(s[i]);
    }
    for (int i = N; i < NN; i++) {
        ori.push_back(s[i]);
    }
    if (ori == rev) {
        for (char i : ori) {
            cout << i;
        }

        cout << "\n" << ans;
        return 0;
    }

    while (ans < N) {
        ori[ans] = s[ans];
        rev.pop_back();
        rev.push_front(s[ans + N]);
        bool ch = true;

        for (int i = ans; i < N; i++) {
            if (ori[i] != rev[i]) {
                ch = false;
                break;
            }
        }

        if (ch) {
            for (char i : ori) {
                cout << i;
            }

            cout << "\n" << ans + 1;
            return 0;
        }
        ans++;
    }

    cout << "-1";

    return 0;
}