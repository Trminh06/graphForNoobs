#include <bits/stdc++.h>

using namespace std;
const int oo=1e9+1;
int n,m,k;
int trace[10000];
int cost[10000];
vector <pair <int ,int> > a[109];
void inp()
{
   // freopen("dijkstra.inp","r",stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        a[u].push_back({v,c});
        a[v].push_back({u,c});
    }
}

void dijkstra(int x,int y, int z)
{
    priority_queue<pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
    memset(trace,0,sizeof(trace));
    for (int i= 1; i <= n; i++)
        cost[i]=oo;
    cost[x]=0;
    pq.push({0,x});
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for (auto i:a[u])
        {
            int v = i.first;
            int w = i.second;
            if (weight != cost[u]) continue;
            if (cost[v] > weight + w)
            {
                cost[v] = weight + w;
                pq.push({cost[v],v});
                trace[v] = u;
            }
        }
    }
    if (z == 0) cout << cost[y] << endl ;
    else
    {
        stack <int> st;
        //cout << y << " " ;
        while (y != x)
        {
            st.push(y);
            y = trace[y];
        }
        st.push(x);
        cout << st.size() << " ";
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}

int main()
{
    inp();
    while (k--)
    {
        int type, u, v;
        cin >> type >> u >> v;
        dijkstra(u,v,type);
    }
    return 0;
}
