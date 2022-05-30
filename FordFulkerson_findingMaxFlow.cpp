#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> ii;
const int maxn = 1e3 + 1;
const int oo = 1e9 + 7;
int n, s, t, trace[maxn], c[maxn][maxn], f[maxn][maxn], d[maxn], ans = 0;
bool vis[maxn];
bool bfs(){
    for(int i = 1; i <= n; ++i)
        d[i] = vis[i] = 0;
    queue <ii> q;
    q.push({s, oo});
    while (q.size()){
        int u = q.front().fi;
        int w = q.front().se;
        vis[u] = true;
        q.pop();
        for(int v = 1; v <= n; ++v){
            if (!vis[v] && min(w, c[u][v] - f[u][v]) > d[v]){
                d[v] = c[u][v] - f[u][v];
                trace[v] = u;
                q.push({v, d[v]});
            }
        }
    }
    return vis[t];
}
void FordFulkerson(){
    int minn = oo;
    int u, v = t;
    while (v != s){
        u = trace[v];
        minn = min(minn, c[u][v] - f[u][v]);
        v = u;
    }
    v = t;
    while (v != s){
        u = trace[v];
        f[u][v] += minn;
        f[v][u] -= minn;
        v = u;
    }
    ans += minn;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, u, v, w;
    cin >> n >> m >> s >> t;
    while (m--){
        cin >> u >> v >> w;
        c[u][v] = w;
    }
    for(int i = 1;  i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f[i][j] = 0;

    while (bfs())
        FordFulkerson();

    cout << ans;
    return 0;
}
