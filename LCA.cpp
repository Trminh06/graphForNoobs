#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e5+1;
const int LOG = 19;
long n,m,k,par[maxn][LOG+1],high[maxn];
vector <int> adj[maxn];
void inp(){
    int u,v;
    cin >> n >> k >> m;
    for(int i = 0; i < n-1; ++i){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void dfs(long u){
    for(auto v:adj[u])
        if (v != par[u][0]){
            par[v][0] = u;
            high[v] = high[u]+1;
            dfs(v);
        }
}
int LCA(int u,int v){
    //gia su high[u] >= high[v]
    if (high[u] < high[v])
        return LCA(v,u);
    for(int i = LOG; i >= 0; --i)
        if (high[par[u][i]] >= high[v])
            u = par[u][i];
    if (u == v)
        return u;
    for(int i = LOG; i >= 0; --i)
        if (par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LCA.inp","r",stdin);
    freopen("LCA.out","w",stdout);
    inp();
    int u,v;
    dfs(k);
    for(int j = 1; j <= LOG; ++j)
        for(int i = 1; i <= n; ++i)
        par[i][j] = par[par[i][j-1]][j-1];
    high[0] = -1;
    while (m--){
        cin >> u >> v;
        cout << LCA(u,v) << "\n";
    }
    return 0;
}
