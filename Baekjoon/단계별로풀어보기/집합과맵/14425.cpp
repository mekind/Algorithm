#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
string s[10010], s2[10010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
    sort(s, s + N);

    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> s2[i];
    }
    sort(s2, s2 + M);
    int idx1 = 0, idx2 = 0;

    while (idx1 < N && idx2 < M)
    {
        string now1 = s[idx1];
        string now2 = s2[idx2];
        // cout << now1 << "  " << now2 << "  hi\n";
        if (now1.compare(now2) == 0)
        {
            idx1++;
            idx2++;
            ans++;
        }
        else if (now1 > now2)
        {
            idx2++;
        }
        else
            idx1++;
    }

    cout << ans;
}