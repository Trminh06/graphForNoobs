#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const int maxn = 3e2 + 7;
const ll oo = 1e18;
struct Edge{
    int v;
    ll flow, cap, cost;
    Edge(int v, ll flow, ll cap, ll cost){
        this -> v = v;
        this -> flow = flow;
        this -> cap = cap;
        this -> cost = cost;
    }
};

struct Flow{
    int n, s, t, trace[maxn], work[maxn];
    ll d[maxn];
    vector <Edge> e;
    vector <int> g[maxn];
    Flow(int n, int s, int t){
        this -> n = n;
        this -> s = s;
        this -> t = t;
    }
    void addEdge(int u, int v, ll cap, ll cost){
        e.push_back(Edge(v, 0, cap, cost));
        g[u].push_back(e.size() - 1);
        e.push_back(Edge(u, 0, 0, -cost));
        g[v].push_back(e.size() - 1);

        e.push_back(Edge(u, 0, cap, cost));
        g[v].push_back(e.size() - 1);
        e.push_back(Edge(v, 0, 0, -cost));
        g[u].push_back(e.size() - 1);
    }
    bool FordBellman(){
        for(int i = 1; i <= n; ++i){
            trace[i] = -1;
            d[i] = oo;
        }
        d[s] = 0;
        for(int i = 1; i <= n; ++i){
            for(int u = 1; u <= n; ++u){
                if (d[u] == oo)
                    continue;
                for(int j : g[u]){
                    if (e[j].cap - e[j].flow == 0)
                        continue;
                    int v = e[j].v;
                    if (d[v] > d[u] + e[j].cost){
                        d[v] = d[u] + e[j].cost;
                        trace[v] = j;
                    }
                }
            }
        }
        return d[t] < oo;
    }
    pair<ll,ll> dfs(int u, ll flow){
        if (u == t)
            return {flow, 0};
        for(int &z = work[u]; z < g[u].size(); ++z){
            int i = g[u][z];
            if (trace[e[i].v] != i || e[i].cap - e[i].flow == 0)
                continue;
            auto tmp = dfs(e[i].v, min(flow, e[i].cap - e[i].flow));
            if (tmp.fi){
                e[i].flow += tmp.fi;
                e[i^1].flow -= tmp.fi;
                tmp.se += tmp.fi * e[i].cost;
                return tmp;
            }
        }
        return {0, 0};
    }
    pair <ll,ll> getFlow(){
        pair <ll,ll> ans = {0, 0};
        while (FordBellman()){
            for(int i = 1; i <= n; ++i)
                work[i] = 0;
            pair <ll,ll> d;
            while ((d = dfs(s, oo)).fi){
                ans.fi += d.fi;
                ans.se += d.se;
            }
        }
        return ans;
    }
    vector <int> res;
    void getPath(int u){
        res.push_back(u);
        if (u == t){
            cout << res.size() - 2 << "\n";
            for(int i = 1; i < res.size() - 1; ++i)
                cout << res[i] << " ";
            cout << "\n";
        }
        for(int i : g[u])
            if (!(i&1) && e[i].flow == e[i].cap)
                getPath(e[i].v);
        res.pop_back();
    }
    void getPath(){
        getPath(s);
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, u, v;
    ll c;
    cin >> n >> m >> u >> v;
    Flow flow = Flow(n + 2, n + 1, n + 2);
    flow.addEdge(n + 1, u, 2, 0);
    flow.addEdge(v, n + 2, 2, 0);
    while (m--){
        cin >> u >> v >> c;
        flow.addEdge(u, v, 1, c);
    }
    pair <ll,ll> ans = flow.getFlow();
    if (ans.fi < 2)
        cout << -1;
    else{
        cout << ans.se << "\n";
        flow.getPath();
    }
    return 0;
}
