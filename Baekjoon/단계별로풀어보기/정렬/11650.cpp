#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
typedef struct Node
{
    int x;
    int y;
};

bool cmp(Node a, Node b)
{
    if (b.x == a.x)
        return a.y < b.y;
    return a.x < b.x;
}

int N;
Node node[100010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> node[i].x >> node[i].y;
    }

    sort(node, node + N, cmp);

    for (int i = 0; i < N; ++i)
    {
        cout << node[i].x << " " << node[i].y << "\n";
    }
}