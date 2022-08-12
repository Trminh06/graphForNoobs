//TASK : https://oj.vnoi.info/problem/fflow
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 1;
const ll oo = 1e18;
struct Edge{
    int v;
    ll flow, cap;
    Edge(int v, ll flow, ll cap){
        this -> v = v;
        this -> flow = flow;
        this -> cap = cap;
    }
};
struct Flow{
    int n, s, t, work[maxn], lv[maxn];
    vector <Edge> e;
    vector <int> g[maxn];
    Flow(int n, int s, int t){
        this -> n = n;
        this -> s = s;
        this -> t = t;
    }
    void addEdge(int u, int v, ll cap){
        e.push_back(Edge(v, 0, cap));
        g[u].push_back(e.size() - 1);
        e.push_back(Edge(u, 0, cap));
        g[v].push_back(e.size() - 1);
    }

    bool bfs(ll cap){
        for(int i = 1; i <= n; ++i)
            lv[i] = 0;
        queue <int> q;
        q.push(s);
        lv[s] = 1;
        while (q.size()){
            int u = q.front();
            q.pop();
            for(int i : g[u]){
                if (e[i].cap - e[i].flow < cap)
                    continue;
                int v = e[i].v;
                if (!lv[v]){
                    lv[v] = lv[u] + 1;
                    q.push(v);
                }
            }
        }
        return lv[t];
    }

    ll dfs(int u, ll flow, ll cap){
        if (u == t)
            return flow;
        for(int &z = work[u]; z < g[u].size(); ++z){
            int i = g[u][z];
            int v = e[i].v;
            if (lv[v] != lv[u] + 1 || e[i].cap - e[i].flow < cap)
                continue;
            ll k = dfs(v, min(flow, e[i].cap - e[i].flow), cap);
            if (k){
                e[i].flow += k;
                e[i^1].flow -= k;
                return k;
            }
        }
        return 0;
    }

    ll Dinic(){
        ll ans = 0;
        for(ll cap = 1 << 30; cap; cap >>= 1)
            while (bfs(cap)){
                for(int i = 1; i <= n; ++i)
                    work[i] = 0;
                ll d;
                while (d = dfs(s, oo, cap))
                    ans += d;
            }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    ll w;
    cin >> n >> m;
    Flow flow = Flow(n, 1, n);
    while (m--){
        cin >> u >> v >> w;
        flow.addEdge(u, v, w);
    }
    cout << flow.Dinic();
    return 0;
}
