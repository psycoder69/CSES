#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n;
    cin >> n;

    vector <vector <char>> maze(n, vector <char> (n));

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cin >> maze[i][j];
        }
    }

    vector <int> paths(n, 0);

    for (int j = 0; j < n and maze[0][j] == '.'; j ++) paths[j] = 1;

    for (int i = 1; i < n; i ++)
    {
        paths[0] &= (maze[i][0] == '.');

        for (int j = 1; j < n; j ++)
        {
            if (maze[i][j] == '.')
            {
                paths[j] = ((paths[j] + paths[j-1]) % MOD);
            }
            else paths[j] = 0;
        }
    }

    cout << paths[n-1];

    return 0;
}