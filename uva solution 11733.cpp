#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class road
{

  public:
  int a,b,c;
  bool operator < (road &q)
  {
    if(c<q.c)return true;
    else return false ;
  }
};

int par[100005];
int find_par(int a)
{
    if(par[a]==a)return a;
    else return find_par(par[a]);
}
int main()

{
//freopen("input.txt","r",stdin);
//
//freopen("output.txt","w",stdout);
    int tst;
    cin>>tst;
    for(int t=1;t<=tst;t++)
    {
        int a,b,c;

        cin>>a>>b>>c;
        vector<road>arr;
        for(int i=1;i<=a;i++)par[i]=i;
        for(int i=0;i<b;i++)

        {
            int x,y,z;
            cin>>x>>y>>z;
            road k;
            k.a=x;
            k.b=y;
            k.c=z;
            arr.push_back(k);
        }
        sort(arr.begin(),arr.end());
        ll cnt=0,sum=0;
        for(int i=0;i<b;i++)
        {
            int u=find_par(arr[i].a);
            int v=find_par(arr[i].b);
            if(u!=v)
            {
                if(arr[i].c>=c)continue;
                par[u]=v;cnt++;
                sum+=arr[i].c;
                if(cnt==a-1)break;
            }
        }
        set<int>s;
        for(int i=1;i<=a;i++)
        {
            int h=find_par(i);
            s.insert(h);
        }
        cout<<"Case #"<<t<<": "<<sum+(s.size()*c)<<' '<< s.size()<<endl;
    }
}
