//TASK : https://cses.fi/problemset/task/2134/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int maxn = 2e5 + 3;
int n, sz[maxn], val[maxn], depth[maxn], par[maxn], id[maxn], idx = 0, tp[maxn];
int st[maxn << 1]; // warning
vector <int> a[maxn];
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
//----using Faster Segtree--------------
void update(int id, int val){
    st[id += n] = val;
    for(id >>= 1; id; id >>= 1)
        st[id] = max(st[id << 1], st[id << 1 | 1]);
}

int get(int l, int r){
    int res = 0;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1)
            maxi(res, st[l++]);
        if (r & 1)
            maxi(res, st[--r]);
    }
    return res;
}
//---------------------------------------
//-----Heavy Light Decomposition---------
int dfsSize(int u, int p){
    sz[u] = 1;
    par[u] = p;
    for(int v : a[u])
        if (v != p){
            depth[v] = depth[u] + 1;
            par[v] = u;
            sz[u] += dfsSize(v, u);
        }
    return sz[u];
}

void HLD(int u, int p, int top){
    id[u] = ++idx;
    tp[u] = top;
    update(id[u], val[u]);
    int heavyChild = 0, heavySize = 0;
    for(int v : a[u])
        if (v != p)
            if (maxi(heavySize, sz[v]))
                heavyChild = v;
    if (!heavyChild)
        return;
    HLD(heavyChild, u, top);
    for(int v : a[u])
        if (v != p && v != heavyChild)
            HLD(v, u, v);
}

int path(int u, int v){
    int res = 0;
    while (tp[u] != tp[v]){
        if (depth[tp[u]] < depth[tp[v]])
            swap(u, v);
        maxi(res, get(id[tp[u]], id[u]));
        u = par[tp[u]];
    }
    if (depth[u] > depth[v])
        swap(u, v);
    maxi(res, get(id[u], id[v]));
    return res;
}
//---------------------------------------
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, u, v, c;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> val[i];
    for(int i = 1; i < n; ++i){
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfsSize(1, 1);
    HLD(1, 1, 1);
    while (q--){
        cin >> c >> u >> v;
        if (c & 1){
            val[u] = v;
            update(id[u], val[u]);
        } else
            cout << path(u, v) << " ";
    }
    return 0;
}

