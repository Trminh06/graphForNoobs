#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
const ll oo = 1e18;
struct Edge{
    int u,v;
    ll w;
};
vector <Edge> a;
int n,trace[maxn];
ll d[maxn];
void Bellman(){
    for(int i = 1; i <= n+1; ++i){
        d[i] = oo;
        trace[i] = -1;
    }
    d[1] = 0;
    ll x = -1;
    for(int i = 0; i < n; ++i){
        x = -1;
        for(auto j : a){
            int u = j.u;
            int v = j.v;
            ll w = j.w;
            if (d[v] > d[u] + w){
                //cout << u << " " << v << "\n";
                d[v] = d[u] + w;
                trace[v] = u;
                x = v;
            }
        }
    }
    //FIND NEGATIVE CYCLE
    if (x == -1)
        //cout << "NO NEGATIVE CYCLE";
        cout << "NO";
    else{
        for(int i = 0; i < n; ++i)
            x = trace[x];
        stack <int> cycle;
        for(int v = x; ; v = trace[v]){
            cycle.push(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        cout << "YES\n";
        while (cycle.size()){
            cout << cycle.top() << " ";
            cycle.pop();
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    Edge s;
    cin >> n >> m;
    while (m--){
        cin >> s.u >> s.v >> s.w;
        a.push_back(s);
    }
    Bellman();
    return 0;
}
