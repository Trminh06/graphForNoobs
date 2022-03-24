#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<long long,long long>
#define ll long long
//#define ll unsigned long long
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 1;
const ll oo = 1e15 + 7;
int n, m, trace[N];
ll cost[N];
vector <ii> a[N];
void dijkstra(){
    priority_queue <ii, vector <ii>, greater<ii>> pq;
    memset(cost, oo, sizeof cost);
    cost[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        ll weight = pq.top().fi;
        ll u = pq.top().se;
        pq.pop();
        for (auto i : a[u]) {
            ll v = i.fi;
            ll w = i.se;
            if (weight != cost[u])
                continue;
            if (cost[v] > weight + w) {
                cost[v] = weight + w;
                pq.push({cost[v], v});
                trace[v] = u;
            }
        }
    }
    if (!trace[n])
        cout << -1;
    else
        cout << cost[n];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        long u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
    }
    for (int i = 1; i <= n; ++i)
        sort(all(a[i]));
       dijkstra();
    return 0;
}
