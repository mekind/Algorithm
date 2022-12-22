#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x, y, w, h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y >> w >> h;

    cout << min(min(x, abs(w - x)), min(y, abs(y - h)));
}