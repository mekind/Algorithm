#include <bits/stdc++.h>
#define MOD 1000
using namespace std;

typedef long long ll;

int testcase;
ll N, B;

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
    vector<vector<ll>> ret = vector(N, vector<ll>(N));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < N; k++) {
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= MOD;
            }
        }
    }

    return ret;
}

vector<vector<ll>> sol(ll n, vector<vector<ll>> a) {
    if (n == 1) return a;

    if (n % 2) {
        vector<vector<ll>> arr = sol(n / 2, mul(a, a));
        return mul(arr, a);
    }

    return sol(n / 2, mul(a, a));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> B;
    vector<vector<ll>> arr(N, vector<ll>(N, 0LL));

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<ll>> ans = sol(B, arr);

    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            cout << ans[i][j] % MOD << " ";
        }
        cout << "\n";
    }

    return 0;
}