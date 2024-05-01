#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;

void markCities(int src, vector <bool>& vis, vector <vector <int>>& graph)
{
    vis[src] = 1;

    for (int& node : graph[src])
    {
        if (not vis[node])
        {
            markCities(node, vis, graph);
        }
    }
}

int main()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL);
    cout.tie (NULL);

    int n, m;
    cin >> n >> m;

    vector <vector <int>> graph(n+1);

    int u, v;

    for (int j = 0; j < m; j ++)
    {
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector <bool> vis(n+1, 0);
    vector <int> disconnected;

    for (int x = 1; x <= n; x ++)
    {
        if (not vis[x])
        {
            disconnected.push_back(x);

            markCities(x, vis, graph);
        }
    }

    int k = disconnected.size();

    cout << (k - 1) << "\n";

    for (int i = 1; i < k; i ++)
    {
        cout << (disconnected[i-1]) << " " << (disconnected[i]) << "\n";
    }

    return 0;
}