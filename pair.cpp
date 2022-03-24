#include <bits/stdc++.h>

using namespace std;
vector <pair<int, int>> a;
int n;
bool ss(const pair<int,int> &x, const pair<int,int> &y)
{
    return x.first<y.first ||   x.first == y.first && x.second < y.second;
}

void nhap()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    { int x,y;
      cin>>x>>y;
      a.push_back(make_pair(x,y));
    }


   //sort(a.begin(),a.end(),ss);
    /*for(auto i=a.begin();i!=a.end();i++)
    {
        cout<<i->first<<":"<<i->second ;
        //cout<<a[i].first<<" "<<a[i].second;
    }
    cout<<endl;
    for(int i=0;i<a.size();i++)
      cout<<a[i].first<<" "<<a[i].second<<endl;
      */
}
void qs(int l, int r)
{
    int i=l, j=r, x=a[(i+j)/2].first;
    int x1=a[(i+j)/2].second;
    while (i<=j )
    {
        while (a[i].first<x || a[i].first==x && a[i].second<x1) i++;
        while (a[j].first>x || a[j].first==x && a[j].second>x1) j--;
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;j--;

        }
    }
    if (l<j) qs(l,j);
    if (i<r) qs(i,r);
}
int main(){
    nhap();
    qs(0,n);
    for(int i = 0; i < a.size(); i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
    return 0;
}
