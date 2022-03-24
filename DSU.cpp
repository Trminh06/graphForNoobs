#include <bits/stdc++.h>
using namespace std;
long n,lab[1000000];
long Root(long u){
    while (lab[u] > 0)
        u = lab[u];
    return u;
    /*
    return lab[u] < 0 ? u :
        lab[u] = get(lab[u]);
    */
}
void Union(long u, long v){
    if (lab[u] <= lab[v])
       swap(u,v);
    lab[u] += lab[v];
    lab[v] = u;
    /*
    if (lab[u] > lab[v]){
        lab[u] += lab[v];
        lab[v] = u;
    } else{
        lab[v] += lab[u];
        lab[u] = v;
    }
    */
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long u,v;
    cin >> n;
    for(long i = 0; i < n; i++){
        cin >> u >> v;
        //cout << "\n";
        long x = Root(u), y = Root(v);
        if (x != y){
            cout << u << " " << v << " " << x << " " << y << "\n";
            Union(x,y);
        }
    }
    return 0;
}
