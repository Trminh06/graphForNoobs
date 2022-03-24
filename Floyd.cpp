#include <bits/stdc++.h>
using namespace std;
const long maxn = 1e8;
long n,m,s,trace[1001][1001],c[1001][1001];
void inp(){
    int u,v;
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = maxn;
    for(int i = 1; i <= m; i++){
        cin >> u >> v >> c[u][v];
        c[v][u] = c[u][v];
    }
}
void floyd(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            trace[i][j] = j;
    for(int k = 1; k <= n; k++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                if (c[u][v] > c[u][k] + c[k][v]){
                    c[u][v] = c[u][k] + c[k][v];
                    trace[u][v] = trace[u][k];
                }
}
void truyvet(int s, int f){
    queue <int> a;
    int t = 1;
    while (s != f){
        a.push(s);
        s = trace[s][f];
        t++;
    }
    a.push(f);
    cout << t;
    while (a.size()){
        cout << " " << a.front();
        a.pop();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    floyd();
    int x,y,z;
    for(int i = 1; i <= s; i++){
        cin >> x >> y >> z;
        if (x == 0)
            cout << c[y][z];
        else
            truyvet(y,z);
        cout << "\n";
    }
    return 0;
}
