#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

void markRoomsBFS(int x, int y, int& n, int& m, vector <vector <char>>& grid)
{
    int dir[] = {-1, 0, 1, 0, -1};

    queue <pair <int, int>> q;
    q.push({x, y});

    grid[x][y] = '#';

    while (not q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int i = 1; i < 5; i ++)
        {
            int r = (x + dir[i-1]), c = (y + dir[i]);

            if (r >= 0 and r < n and c >= 0 and c < m and grid[r][c] == '.')
            {
                grid[r][c] = '#';
                q.push({r, c});
            }
        }
    }
}

void markRoomsDFS(int x, int y, int& n, int& m, vector <vector <char>>& grid)
{
    if (x < 0 or y < 0 or x == n or y == m or grid[x][y] == '#') return;

    grid[x][y] = '#';

    int dir[] = {-1, 0, 1, 0, -1};

    for (int i = 1; i < 5; i ++)
    {
        markRoomsDFS(x + dir[i-1], y + dir[i], n, m, grid);
    }
}

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <char>> grid(n, vector <char> (m));

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            cin >> grid[i][j];
        }
    }

    int rooms = 0;

    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < m; j ++)
        {
            if (grid[i][j] == '.')
            {
                rooms ++;
                // markRoomsBFS(i, j, n, m, grid);
                markRoomsDFS(i, j, n, m, grid);
            }
        }
    }

    cout << (rooms);

    return 0;
}