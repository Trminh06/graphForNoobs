#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 1;
const ll oo = 1e18;
int n, s, t, lv[maxn];
ll f[maxn][maxn], c[maxn][maxn], ans = 0;
vector <int> a[maxn];
bool bfs(){
    for(int i = 1; i <= n; ++i){
        lv[i] = -1;
    }
    lv[s] = 0;
    queue <int> q;
    q.push(s);
    while (q.size()){
        int u = q.front();
        q.pop();
        for(int v : a[u]){
            if (lv[v] >= 0 || f[u][v] >= c[u][v])
                continue;
            lv[v] = lv[u] + 1;
            q.push(v);
        }
    }
    return lv[t] > 0;
}

ll dfs(int u, ll pushF){
    if (!pushF || u == t)
        return pushF;
    for(int v : a[u]){
        if (lv[v] != lv[u] + 1 || f[u][v] >= c[u][v])
            continue;
        ll k = dfs(v, min(pushF, c[u][v] - f[u][v]));
        if (!k)
            continue;
        f[u][v] += k;
        f[v][u] -= k;
        return k;
    }
    return 0;
}

void Dinic(){
    while (bfs())
        ans += dfs(s, oo);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, u, v;
    cin >> n >> m >> s >> t;
    while (m--){
        cin >> u >> v >> c[u][v];
        a[u].push_back(v);
        a[v].push_back(u);
    }
    Dinic();
    return 0;
}
