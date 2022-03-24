#include <bits/stdc++.h>

using namespace std;
const long maxn = 10e5;
vector <long> a[maxn];
long n,m,s,f,trace[maxn];
queue <long> q;
void inp(){
    cin >> n >> m >> s >> f;
    for(long i = 1; i <= m; i++){
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void bfs(long k){
    trace[k] = -1;
    q.push(k);
    while (!q.empty()){
        long u = q.front();
        q.pop();
        for(auto it:a[u]){
            if (trace[it] == 0){
                q.push(it);
                trace[it] = u;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BFS.inp","r",stdin);
    freopen("BFS.out","w",stdout);
    inp();
    bfs(s);
    for(long i = 1; i <= n; i++)
        cout << trace[i] << " ";
    return 0;
}
