#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class node
{
    public:
    ll sum,prop;
};
node tree[4*100005];
int a[100005];

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        tree[pos].sum=a[lo];
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
}

void update(int pos ,int lo,int hi,int x,int y,ll v)
{
    if(lo>y||hi<x)return;
    if(lo>=x&&hi<=y)
    {
        tree[pos].sum+=((hi-lo+1)*v);
        tree[pos].prop+=v;
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    update(left,lo,mid,x,y,v);
    update(right,mid+1,hi,x,y,v);
    tree[pos].sum=tree[left].sum+tree[right].sum+((hi-lo+1)*tree[pos].prop);
}
ll query(int pos ,int lo, int hi, int x ,int y, ll c=0)
{
    if(lo>y||hi<x)return 0;
    if(lo>=x&&hi<=y)
    {
        return tree[pos].sum+(c*(hi-lo+1));
    }

    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    ll p=0;
    p+=query(left,lo,mid,x,y,tree[pos].prop+c);
    p+=query(right,mid+1,hi,x,y,tree[pos].prop+c);
    return p;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<(4*n);i++)
        {
            tree[i].sum=0;
            tree[i].prop=0;
        }
        build(0,0,n-1);
        printf("Case %d:\n",t);
        while(q--)
        {
            int k,a,b,c;
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d %d",&a,&b);
                printf("%lld\n",query(0,0,n-1,a,b,0));

            }
            else
            {
                scanf("%d %d %d",&a,&b,&c);
                update(0,0,n-1,a,b,c);

            }
        }

    }
}
