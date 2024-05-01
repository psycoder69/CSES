#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    string s;
    cin >> s;

    int len = s.length(), curr = 1, maxx = 1;

    for (int i = 1; i < len; i ++)
    {
        if (s[i-1] != s[i])
        {
            maxx = max(maxx, curr);
            curr = 1;
        }
        else curr ++;
    }

    maxx = max(maxx, curr);

    cout << (maxx);

    return 0;
}