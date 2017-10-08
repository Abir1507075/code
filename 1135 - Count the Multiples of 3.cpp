#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
    public:
    ll one ,two,zero;
    node():one(0),two(0),zero(0){}
    node(int a,int b,int c):zero(a),one(b),two(c){}

    void update()
    {
        int temp=two;
        two=one;
        one=zero;
        zero=temp;
    }
};
int a[100003];
node tree[3*100004];
int prop[3*100004];
void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        tree[pos]=node(1,0,0);
        return;
    }
    int left=2*pos+1;
    int right=2*pos+2;
    int mid=(lo+hi)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
    tree[pos].zero=tree[left].zero+tree[right].zero;
    tree[pos].one=tree[left].one+tree[right].one;
    tree[pos].two=tree[left].two+tree[right].two;
}

void push(int pos,int lo,int hi)
{
    if(prop[pos]==0)return;
    int left=2*pos+1;
    int right=2*pos+2;
    int mid=(lo+hi)/2;
    prop[pos]%=3;
    prop[left]+=prop[pos];
    prop[right]+=prop[pos];
    for(int i=0;i<prop[pos];i++)
    {
        tree[left].update();
        tree[right].update();
    }
    prop[pos]=0;

}
void update(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return;
    if(lo>=x&&hi<=y)
    {
        tree[pos].update();
        prop[pos]++;
        return;
    }
    int left=2*pos+1;
    int right=2*pos+2;
    int mid=(lo+hi)/2;
    push(pos,lo,hi);
    update(left,lo,mid,x,y);
    update(right,mid+1,hi,x,y);
    tree[pos].zero=tree[left].zero+tree[right].zero;
    tree[pos].one=tree[left].one+tree[right].one;
    tree[pos].two=tree[left].two+tree[right].two;
}
ll query(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return 0;
    if(lo>=x&&hi<=y)
    {
        return tree[pos].zero;
    }
    push(pos,lo,hi);
    int left=2*pos+1;
    int right=2*pos+2;
    int mid=(lo+hi)/2;
    ll p1=query(left,lo,mid,x,y);
    ll p2=query(right,mid+1,hi,x,y);
    return p1+p2;
}
int main()
{
    int tst;
//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        memset(prop,0,sizeof(prop));
        int n,q;
        scanf("%d %d",&n,&q);
        build(0,0,n-1);
        printf("Case %d:\n",t);
        for(int i=0;i<q;i++)
        {
            ll a,b,c;
            scanf("%lld %lld %lld",&c,&a,&b);
            if(c==1)
            {
                ll ans=query(0,0,n-1,a,b);
                printf("%lld\n",ans);
            }
            else
            {
                update(0,0,n-1,a,b);
            }
        }
    }

}
