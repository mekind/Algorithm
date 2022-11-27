#include <iostream>
#include <string>
using namespace std;

int testcase;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> testcase;

  while (testcase--)
  {
    string word;
    cin >> word;

    string ans = word;

    for (int i = word.length() - 1; i >= 0; --i)
    {
      ans += word[i];
    }

    cout << ans << "\n";
  }

  return 0;
}