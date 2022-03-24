#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long maxn = 1e5+1;
long low[maxn],num[maxn],n,cnt = 0,ans = 0,lastC[maxn],cntC = 0;
vector <long> a[maxn];
stack <long> st;
void inp(){
    long m,u,v;
    cin >> n >> m;
    while (m--){
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void Tarjan(long u){
    low[u] = num[u] = ++cnt;
    for(long i = 0,v; v = a[u][i]; ++i){
        if (num[v])
            low[u] = min(low[u],num[v]);
        else{
            st.push(u);
            Tarjan(v);
            low[u] = min(low[u],low[v]);
            if (low[v] >= num[u]){
                long C = 0;
                ++cntC;
                do{
                    v = st.top();
                    st.pop();
                    if (lastC[v] < cntC){
                        lastC[v] = cntC;
                        cout << v << " ";
                        ++C;
                    }
                } while (u != v);
                ans = max(ans,C);
                cout << "\n";
            }
        }
    }
    st.push(u);
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("SAFENET.inp","r",stdin);
    //freopen("SAFENET.out","w",stdout);
    inp();
    cout << "\n";
    for(int i = 1; i <= n; ++i)
        a[i].push_back(0);
    for(int i = 1; i <= n; ++i)
          if (!num[i])
            Tarjan(i);
    if (ans)
        cout << ans << "\n";
    else
        cout << 1 << "\n";
    return 0;
}


