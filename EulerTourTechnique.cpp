//TASK : https://cses.fi/problemset/task/1137/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int maxn = 2e5 + 1;
ll bit[maxn], a[maxn];
int n, cnt, st[maxn], en[maxn];
vector <int> adj[maxn];
template <typename T1, typename T2> bool maxi(T1 &a, T2 b){
    if (a < b)
        a = b;
    else
        return 0;
    return 1;
}
template <typename T1, typename T2> bool mini(T1 &a, T2 b){
    if (a > b)
        a = b;
    else
        return 0;
    return 1;
}

void update(int x, ll val){
    for(; x <= n; x += x & (-x))
        bit[x] += val;
}

ll get(int x){
    ll res = 0;
    for(; x; x -= x & (-x))
        res += bit[x];
    return res;
}

void dfs(int u, int p){
    st[u] = ++cnt;
    for(int v : adj[u])
        if (v != p)
            dfs(v, u);
    en[u] = cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, u, v;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i < n; ++i){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i)
        update(st[i], a[i]);
    while (q--){
        cin >> u;
        if (u & 1){
            cin >> u >> v;
            update(st[u], v - a[u]);
            a[u] = v;
        } else{
            cin >> u;
            cout << get(en[u]) - get(st[u] - 1) << "\n";
        }
    }
    return 0;
}
