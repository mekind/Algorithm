#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

typedef struct User
{
    int cnt;
    int age;
    char name[110];
};

bool cmp(User a, User b)
{
    if (a.age == b.age)
        return a.cnt < b.cnt;
    return a.age < b.age;
}

int N;
User user[100010];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> user[i].age >> user[i].name;
        user[i].cnt = i;
    }

    sort(user, user + N, cmp);

    for (int i = 0; i < N; i++)
    {
        cout << user[i].age << " " << user[i].name << "\n";
    }
}