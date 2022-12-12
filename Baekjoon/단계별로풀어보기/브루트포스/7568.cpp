#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

typedef struct Node
{
    int x;
    int y;
};

int N;
Node node[55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> node[i].x >> node[i].y;
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (node[j].x > node[i].x && node[j].y > node[i].y)
            {
                cnt++;
            }
        }
        cout << cnt + 1 << " ";
    }
}