#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;
vector<ll> prm;
bool ch[5000010];

void pre() {
    for (int i = 2; i <= 5000000; i++) {
        if (!ch[i]) {
            for (int j = i * 2; j <= 5000000; j += j) {
                ch[j] = true;
            }
            prm.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    cin >> testcase;

    while (testcase--) {
        ll N;
        cin >> N;
        ll p = 0LL, q = 0LL;
        for (int i = 0; i < prm.size(); i++) {
            ll now = prm[i] * prm[i];

            if (N % now == 0) {
                p = sqrt(now);
                q = N / now;
                break;
            }
            if (N % prm[i] == 0) {
                p = sqrt(N / prm[i]);
                q = prm[i];
            }
        }

        cout << p << " " << q << "\n";
    }

    return 0;
}