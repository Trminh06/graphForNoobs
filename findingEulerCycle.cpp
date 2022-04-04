#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 2e5 + 1;
vector <pair<int,int>> a[maxn];
bool vis[maxn];
int n, m;
void findEuler(){
    stack <int> st;
    st.push(2);
    vector <int> path;
    while (st.size()){
        int v = st.top();
        int f = 0;
        while (a[v].size()){
            pair<int,int> p = a[v].back();
            a[v].pop_back();
            if (!vis[p.se]){
                st.push(p.fi);
                vis[p.se] = true;
                f = 1;
                break;
            }
        }
        if (!f){
            path.push_back(v);
            st.pop();
        }
    }
    if (path.size() != m + 1)
        cout << "IMPOSSIBLE";
    else {
        for(int i : path)
            cout << i << " ";
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> u >> v;
        a[u].push_back({v,i});
        a[v].push_back({u,i});
    }
    for(int i = 1; i <= n; ++i){
        vis[i] = false;
        if (a[i].size() & 1){
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
    findEuler();
    return 0;
}

