#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> ii;
const int maxn = 1e3 + 1;
const int oo = 1e9 + 7;
int n, s, t, trace[maxn], c[maxn][maxn], f[maxn][maxn], d[maxn], ans = 0;
vector <int> a[maxn];
bool bfs(){
    for(int i = 1; i <= n; ++i)
        d[i] = trace[i] = 0;
    queue <int> q;
    q.push(s);
    d[s] = 1;
    while (q.size()){
        int u = q.front();
        q.pop();
        for(int v : a[u]){
            if (d[v] || f[u][v] >= c[u][v])
                continue;
            trace[v] = u;
            d[v] = 1;
            if (v == t)
                return 1;
            q.push(v);
        }
    }
    return trace[t];
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
        a[u].push_back(v);
        a[v].push_back(u);
    }
    while (bfs())
        FordFulkerson();

    cout << ans;
    return 0;
}
