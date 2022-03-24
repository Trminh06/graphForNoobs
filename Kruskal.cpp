#include <bits/stdc++.h>
using namespace std;
//#define fi first;
//#define se second;
typedef pair<int,pair<int,int>> ii;
priority_queue<ii,vector <ii>, greater<ii>> q;
int m,n,lab[100001];
void inp(){
    int u,v,w;
    cin >> n >> m; //n dinh m canh
    for(int i = 0;i < m; i++){
        cin >> u >> v >> w;
        q.push(ii(w,{u,v}));
    }
    memset(lab,-1,sizeof(lab));
}
void Union(int u, int v){
    if (lab[u] > lab[v])
        swap(u,v);
    lab[u] += lab[v];
    lab[v] = u;
}
int get(int u){
    /*
    while (lab[u] > 0)
        u = lab[u];
    return u;
    */
    return lab[u] < 0 ? u :
        lab[u] = get(lab[u]);
}
void Kruskal(){
    int d = 0;
    long sum = 0;
    while (d < n-1){
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = q.top().first;
        q.pop();
        int x = get(u), y = get(v);
        if (x != y){
            Union(x,y);
            d++;
            sum += w;
        }
    }
    cout << sum << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    Kruskal();
    return 0;
}
