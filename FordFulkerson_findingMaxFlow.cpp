#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 1;
const ll oo = 1e18;
int n, s, t, trace[maxn];
ll f[maxn][maxn], ans = 0;
bool vis[maxn];
vector <int> a[maxn];
bool bfs(){
    for(int i = 1; i <= n; ++i)
        vis[i] = 0;
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    trace[s] = -1;
    while (q.size()){
        int u = q.front();
        q.pop();
        for(int v : a[u]){
            if (vis[v] || f[u][v] <= 0)
                continue;
            vis[v] = 1;
            trace[v] = u;
            q.push(v);
        }
    }
    return vis[t];
}
void FordFulkerson(){
    int u, v = t;
    ll minn = oo;
    while (v != s){
        u = trace[v];
        minn = min(minn, f[u][v]);
        v = u;
    }
    v =  t;
    while (v != s){
        u = trace[v];
        f[u][v] -= minn;
        f[v][u] += minn;
        v = u;
    }
    ans += minn;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, u, v;
    ll c;
    cin >> n >> m >> s >> t;
    while (m--){
        cin >> u >> v >> c;
        f[u][v] = c;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    while (bfs())
        FordFulkerson();
    cout << ans;
    return 0;
}
