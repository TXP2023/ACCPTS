#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
struct node {
    int to, edge;
};
int d[N][N];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int vis[N][N];
char c[N][N];
int n, m, x, y;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
void dijkstra(int x, int y) {
    d[x][y] = 0;
    q.push({ 0,{x,y} });
    while (!q.empty()) {
        // cout<<x<<" "<<y<<" "<<d[x][y]<<endl;
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        if (vis[x][y])continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || ny <= 0 || nx > n || ny > m || c[nx][ny] == '#')continue;
            if (vis[nx][ny])continue;
            int dxy = (int)(c[x][y] - '0');
            int dnxy = (int)(c[nx][ny] - '0');
            if (dxy >= dnxy)d[nx][ny] = min(d[nx][ny], d[x][y] + 1);
            else d[nx][ny] = min(d[nx][ny], d[x][y] + dnxy - dxy + 1);
            q.push({ d[nx][ny],{nx,ny} });
        }
    }
}
int main() {
    //	freopen("118.in","r",stdin);
    //	freopen("118.out","w",stdout);
    memset(d, 0x3f, sizeof(d));
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }
    cin >> x >> y;
    dijkstra(x, y);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] == 0x3f3f3f3f)cout << -1 << " ";
            else cout << d[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}