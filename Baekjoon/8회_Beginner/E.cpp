#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

typedef struct birth
{
    int month;
    int day;
};
typedef struct star
{
    birth start;
    birth end;
};

bool cmp(birth a, birth b)
{
    if (a.month == b.month)
        return a.day < b.day;
    return a.month < b.month;
}

int N;

star stars[12];
bool pos[12];
int aloha[7];
vector<birth> mem_birth;

int tmp1, tmp2;

int what_star(int mon, int day)
{
    for (int j = 0; j < 11; ++j)
    {
        if (stars[j].start.month == mon && stars[j].start.day <= day)
            return j;
        if (stars[j].end.month == mon && stars[j].end.day >= day)
            return j;
    }
    return 11;
}

void set_stars()
{
    stars[0].start = {1, 20};
    stars[0].end = {2, 18};

    stars[1].start = {2, 19};
    stars[1].end = {3, 20};

    stars[2].start = {3, 21};
    stars[2].end = {4, 19};

    stars[3].start = {4, 20};
    stars[3].end = {5, 20};

    stars[4].start = {5, 21};
    stars[4].end = {6, 21};

    stars[5].start = {6, 22};
    stars[5].end = {7, 22};

    stars[6].start = {7, 23};
    stars[6].end = {8, 22};

    stars[7].start = {8, 23};
    stars[7].end = {9, 22};

    stars[8].start = {9, 23};
    stars[8].end = {10, 22};

    stars[9].start = {10, 23};
    stars[9].end = {11, 22};

    stars[10].start = {11, 23};
    stars[10].end = {12, 21};

    stars[11].start = {12, 22};
    stars[11].end = {1, 19};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set_stars();

    for (int i = 0; i < 7; ++i)
    {
        cin >> tmp1 >> tmp2;
        aloha[i] = what_star(tmp1, tmp2);
        // cout << tmp1 << " " << tmp2 << " " << aloha[i] << "  star\n";s

        pos[aloha[i]] = true;
    }

    cin >> N;

    for (int i = 0; i < N; ++i)
    {

        cin >> tmp1 >> tmp2;

        int nm = what_star(tmp1, tmp2);

        if (!pos[nm])
        {
            // cout << tmp1 << "   " << tmp2 << "   " << nm << "  right?" << pos[nm] << "\n";
            mem_birth.push_back({tmp1, tmp2});
        }
    }
    sort(mem_birth.begin(), mem_birth.end(), cmp);

    for (int i = 0; i < mem_birth.size(); ++i)
    {
        cout << mem_birth[i].month << " " << mem_birth[i].day << "\n";
    }

    if (mem_birth.size() == 0)
        cout << "ALL FAILED\n";
    return 0;
}