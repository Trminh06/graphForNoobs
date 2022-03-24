#include <bits/stdc++.h>
const int maxn=10000;
using namespace std;
long n,m,s,f;
int trace[maxn];
vector <int> a[maxn];
void nhap()
{
    cin>>n>>m>>s>>f;
    for (int i=1;i<=m;i++)
    {int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
   // for(int i=1;i<=n;i++)
   // { cout<<i<<": ";
    // for(auto v:a[i])
      //      cout<<v<<" ";
    //    cout<<endl;
  //  }
}
void dfs(int u)
{
    for(auto v:a[u])
        if (trace[v]==0)
        {
            trace[v]=u;
            dfs(v);
        }
}
void truyvet()
{
    cout<<f;
    while (f!=s)
    {
        f=trace[f];
        cout<<f;
    }

}
int main()
{
    nhap();
    trace[s]=-1;
    dfs(s);
    for(int i=1;i<=n;i++)
        cout<<trace[i]<<" ";
    cout<<endl;
    truyvet();
    return 0;
}
/*
#include <bits/stdc++.h>
const int maxn=10000;
using namespace std;
long n,m,s,f;
int trace[maxn];
vector <int> a[maxn];
void nhap()
{
    freopen("graph.inp","r",stdin);
    cin>>n>>m>>s>>f;
    for (int i=1;i<=m;i++)
    {int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
   // for(int i=1;i<=n;i++)
   // { cout<<i<<": ";
    // for(auto v:a[i])
      //      cout<<v<<" ";
    //    cout<<endl;
  //  }
}
void dfs(int u)
{
    for(auto v:a[u] )
        if (trace[v]==0)
{
    trace[v]=u;
    dfs(v);
}
}
void truyvet()
{
    if (trace[f]==0)
        cout<<"..";
    else
    {

    cout<<f;
    while (f!=s)
    {
        f=trace[f];
        cout<<f;
    }
    }
}
int main()
{
    int dem=0;
    nhap();
    memset(trace,0,sizeof(trace));
    trace[s]=-1;
    dfs(s);
    truyvet();
    memset(trace,0,sizeof(trace));
   for(int i=1;i<=n;i++)
   {
        if(trace[i]==0)
        {
            dem++;
            trace[i]=-1;
            dfs(i);
        }

   }
 cout<<dem;
    ret

*/
