#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int g;
    cin >> g;
    vector<int> dep(g + 1);
    for (int i = 1; i <= g; i++) {
        cin >> dep[i];
    }

    int q;
    cin >> q;
    while (q--) {
        int x, s, t;
        cin >> x >> s >> t;

        vector<vector<bool>> visited(n + 1, vector<bool>(g + 1, false));
        vector<int> res(n + 1, 0);
        queue<pair<int, int>> que;

        visited[x][s] = true;
        que.push({ x, s });
        if (s == t) res[x] = 1;

        while (!que.empty()) {
            pair<int, int> now = que.front();
            que.pop();
            int cur = now.first;
            int prod = now.second;
            

            int r = dep[prod];
            if (r == 0) continue;

            for (int nxt : graph[cur]) {
                if (!visited[nxt][r]) {
                    visited[nxt][r] = true;
                    que.push({ nxt, r });
                    if (r == t) {
                        res[nxt] = 1;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << res[i] << " \n"[i == n];
        }
    }

    return 0;
}