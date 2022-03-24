#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
vector <int> a[maxn];
//Kahn's algorithm for topological sort
int indegree[maxn], n;
vector <int> topoOrder;

//dfs for topological sort
int d[maxn],num[maxn];
stack <int> topo;

void Kahn(){
    queue <int> q;
    for(int i = 1; i <= n; ++i)
        if (!indegree[i]){
            q.push(i);
            topoOrder.push_back(i);
        }
    while (q.size()){
        int u = q.front();
        q.pop();
        for(auto v : a[u]){
            indegree[v]--;
            if (!indegree[v]){
                q.push(v);
                topoOrder.push_back(v);
            }
        }
    }
}

void dfs(int u){
    d[u] = 1;
    //cout << u << "\n";
    for(auto v : a[u])
        if (!d[v]){
            d[u] = 1;
            //trace[v] = u;
            dfs(v);
        } else
            if (d[v] == 1){
                cout << "OOPS THIS GRAPH IS NOT A DAG";
                exit(0);
            }
    topo.push(u);
    d[u] = 2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,u,v;
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        a[u].push_back(v);
    }

    //find indegree
    fill_n(indegree,0,n);
    for(int i = 1; i <= n; ++i)
        for(auto j : a[i])
            indegree[j]++;
    Kahn();
    if (topoOrder.size()){
        for(auto i : topoOrder)
            cout << i << " ";
    } else
        cout << "NO TOPOLOGICAL SORT";
    cout << "-----------------------------\n";

    //topological sort but dfs version
    fill_n(d,0,n);
    for(int i = 1; i <= n; ++i)
        if (!d[i])
            dfs(i);
    int cnt = 0;
    while (topo.size()){
        num[topo.top()] = ++cnt;
        topo.pop();
    }
    for(int i = 1; i <= n; ++i)
        cout << num[i] << " ";
    return 0;
}

