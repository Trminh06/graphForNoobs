//source : https://cses.fi/problemset/task/1696/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 69;
const int oo = 1e9 + 7;
int trace[maxn];
struct Edge{
    int v, flow, cap;
    Edge(int v, int flow, int cap){
        this -> v = v;
        this -> flow = flow;
        this -> cap = cap;
    }
};
struct Flow{
    int n, s, t, lv[maxn], work[maxn];
    vector <Edge> e;
    vector <int> g[maxn];
    Flow(int n, int s, int t){
        this -> n = n;
        this -> s = s;
        this -> t = t;
    }
    void addEdge(int u, int v){
        e.push_back(Edge(v, 0, 1));
        g[u].push_back(e.size() - 1);
        e.push_back(Edge(u, 0, 0));
        g[v].push_back(e.size() - 1);
    }

    bool bfs(int cap){
        for(int i = 0; i <= n; ++i)
            lv[i] = 0;
        queue <int> q;
        q.push(s);
        lv[s] = 1;
        while (q.size()){
            int u = q.front();
            q.pop();
            for(int i : g[u]){
                int v = e[i].v;
                if (lv[v] || e[i].cap - e[i].flow < cap)
                    continue;
                lv[v] = lv[u] + 1;
                q.push(v);
            }
        }
        return lv[t];
    }

    int dfs(int u, int flow, int cap){
        if (u == t)
            return flow;
        for(int &z = work[u]; z < g[u].size(); ++z){
            int i = g[u][z];
            int v = e[i].v;
            if (lv[v] != lv[u] + 1 || e[i].cap - e[i].flow < cap)
                continue;
            int k = dfs(v, min(flow, e[i].cap - e[i].flow), cap);
            if (k){
                e[i].flow += k;
                e[i^1].flow -= k;
                trace[v] = u;
                return k;
            }
        }
        return 0;
    }

    int Dinic(){
        int ans = 0;
        while (bfs(1)){
            for(int i = 0; i <= n; ++i)
                work[i] = 0;
            while (dfs(s, oo, 1)){
                ans++;
                //cout << "\n";
            }
        }
        return ans;
    }
    void Debug(){
        cout << "\n";
        for(int i = 0; i <= n; ++i)
            cout << trace[i] << " ";
    }
};
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp","r",stdin);
    int n, m, k, u, v;
    cin >> n >> m >> k;
    for(int i = 0; i <= n + m + 1; ++i)
        trace[i] = -1;
    Flow flow = Flow(n + m + 1, 0, n + m + 1);
    while (k--){
        cin >> u >> v;
        flow.addEdge(u, n + v);
    }
    for(int i = 1; i <= n; ++i)
        flow.addEdge(0, i);
    for(int i = 1; i <= m; ++i)
        flow.addEdge(n + i, n + m + 1);
    cout << flow.Dinic() << "\n";
    for(int i = n + 1; i <= n + m; ++i)
        if (trace[i] != -1)
            cout << trace[i] << " " << i - n << "\n";
    //flow.Debug();
    return 0;
}

