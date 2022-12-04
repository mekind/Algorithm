#include <iostream>
#include <algorithm>
using namespace std;

bool students[35];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 28; i++)
    {
        int tmp;
        cin >> tmp;
        students[tmp] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!students[i])
            cout << i << "\n";
    }
}