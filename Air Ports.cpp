#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int src,des,cost;
};

bool cmp(node p,node q)
{
    if(p.cost<q.cost)return true;
    else return false;
}
int par[200000];
int f_par(int n)
{
    if(par[n]==n)return n;
    else return f_par(par[n]);
}
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int n,m,c;
        scanf("%d %d %d",&n,&m,&c);
        node arr[m+5];
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int a,b,cost;
            scanf("%d %d %d",&a,&b,&cost);
            node temp;
            arr[i].src=a;
            arr[i].des=b;
            arr[i].cost=cost;
        }
        sort(arr,arr+m,cmp);
        int edge=0,cost=0,cnt=0;
        for(int i=0;i<m;i++)
        {
            int x=f_par(arr[i].src);
            int y=f_par(arr[i].des);

            if(x==y)continue;
            if(arr[i].cost>=c)continue;
            par[x]=y;
            edge++;
            cost+=arr[i].cost;

            if(edge==n-1)break;
        }

        printf("Case %d: %d %d\n",t,cost+(n-edge)*c,(n-edge));

        memset(par,0,sizeof par);
    }
}
