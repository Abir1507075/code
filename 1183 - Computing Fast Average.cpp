#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class node
{
    public:
    ll sum,prop;
    node():sum(0),prop(-1){}
};

int arr[100003];
node tree[3*100005];

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        tree[pos].sum=arr[lo];
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
    tree[pos].sum=tree[left].sum+tree[right].sum;
}
void push(int pos,int lo,int hi)
{
    if(tree[pos].prop==-1)return;
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    tree[left].sum=tree[pos].prop*(mid-lo+1);
    tree[right].sum=tree[pos].prop*(hi-mid);
    tree[left].prop=tree[right].prop=tree[pos].prop;
    tree[pos].prop=-1;
}

void  update(int pos,int lo,int hi,int x,int y,int w)
{
    if(lo>y||hi<x) return;
    if(lo>=x&&hi<=y)
    {
        tree[pos].sum=(hi-lo+1)*w;
        tree[pos].prop=w;
        return;
    }
    push(pos,lo,hi);
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    update(left,lo,mid,x,y,w);
    update(right,mid+1,hi,x,y,w);
    tree[pos].sum=tree[right].sum+tree[left].sum;

}
ll query(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return  0;
    if(lo>=x&&hi<=y)
    {
        return tree[pos].sum;
    }
    push(pos,lo,hi);
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    ll p1=query(left,lo,mid,x,y);
    ll p2=query(right,mid+1,hi,x,y);
    return p1+p2;
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
        build(0,0,n-1);
        printf("Case %d:\n",t);
        for(int i=0;i<q;i++)
        {
            ll k,a,b,c;
            scanf("%lld",&k);

            if(k==1)
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                update(0,0,n-1,a,b,c);
            }
            else
            {
                scanf("%lld %lld",&a,&b);
                ll temp=query(0,0,n-1,a,b);
                ll ans=temp/(b-a+1);
                int g=__gcd(temp,(b-a+1));
                if(ans*(b-a+1)==temp)printf("%lld\n",ans);
                else
                {
                    ll f=temp/g;
                    ll t=(b-a+1)/g;
                    printf("%lld/%lld\n",f,t);
                }
            }
        }

        for(int i=0;i<3*n;i++)
        {
            tree[i].prop=-1;
            tree[i].sum=0;
        }

    }


}
