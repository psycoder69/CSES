#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

string findPath(int x, int y, int& n, int& m, vector <vector <char>>& grid)
{
    string path;

    vector <vector <char>> dir(n, vector <char> (m, '.'));

    queue <pair <int, int>> q;
    q.push({x, y});

    dir[x][y] = 'S';
    grid[x][y] = '#';

    while (not q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        if (grid[x][y] == 'B')
        {
            while (dir[x][y] != 'S')
            {
                path.push_back(dir[x][y]);

                if (dir[x][y] == 'U') x ++;
                else if (dir[x][y] == 'L') y ++;
                else if (dir[x][y] == 'D') x --;
                else y --;
            }

            reverse(begin(path), end(path));

            return path;
        }

        if (x > 0 and grid[x-1][y] != '#')
        {
            if (grid[x-1][y] == '.') grid[x-1][y] = '#';

            q.push({x-1, y});
            dir[x-1][y] = 'U';
        }

        if (y > 0 and grid[x][y-1] != '#')
        {
            if (grid[x][y-1] == '.') grid[x][y-1] = '#';

            q.push({x, y-1});
            dir[x][y-1] = 'L';
        }

        if (x < n-1 and grid[x+1][y] != '#')
        {
            if (grid[x+1][y] == '.') grid[x+1][y] = '#';

            q.push({x+1, y});
            dir[x+1][y] = 'D';
        }

        if (y < m-1 and grid[x][y+1] != '#')
        {
            if (grid[x][y+1] == '.') grid[x][y+1] = '#';

            q.push({x, y+1});
            dir[x][y+1] = 'R';
        }
    }

    return "";
}

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <char>> grid(n, vector <char> (m));

    int x = 0, y = 0;

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A') x = i, y = j;
        }
    }

    string path = findPath(x, y, n, m, grid);

    cout << (path.empty() ? "NO\n" : "YES\n");

    if (not path.empty()) cout << (path.length()) << "\n" << (path);

    return 0;
}