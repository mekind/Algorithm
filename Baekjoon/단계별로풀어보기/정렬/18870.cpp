#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

int N;
int X[1000010], XX[1000010];
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        XX[i] = X[i];
    }

    sort(X, X + N);
    v.push_back(X[0]);
    for (int i = 1; i < N; i++)
    {
        if (X[i] != X[i - 1])
            v.push_back(X[i]);
    }
    int M = v.size();

    for (int i = 0; i < N; i++)
    {
        int now = XX[i];
        int idx = lower_bound(v.begin(), v.end(), now) - v.begin();
        // cout << now << " " << idx << " dd\n";
        cout << idx << " ";
    }
}