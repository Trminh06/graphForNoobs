#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
vector <pair<long,long>> a[100001];
ll dp[100001],res = 0;
void inp(){
    int u,v,w;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        a[u].push_back({v,w});
    }
}
ll dfs(int u){
    if (dp[u] != -1)
        return dp[u];
    dp[u] = 0;
    for(auto v:a[u])
        dp[u] = max(dp[v.second],dfs(v.first)+v.second);
    return dp[u];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    memset(dp,-1,sizeof(dp));
    for(int i = 1; i <= n; i++)
        res = max(res,dfs(i));
    cout << res << "\n";
    return 0;
}
