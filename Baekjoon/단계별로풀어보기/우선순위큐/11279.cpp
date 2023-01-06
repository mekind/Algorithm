#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int testcase;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (!tmp) {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(tmp);
        }
    }

    return 0;
}