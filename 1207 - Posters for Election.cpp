#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define mx 100002
int arr[mx*2];
int tree[6*mx];
int prop[6*mx];

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        tree[pos]=arr[lo];
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
}
void push(int pos,int lo,int hi)
{
    if(prop[pos]==-1)return;
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    prop[left]=prop[right]=prop[pos];
    tree[left]=prop[pos]*(mid-lo+1);
    tree[right]=prop[pos]*(hi-mid);
    prop[pos]=-1;
}
void update(int pos,int lo,int hi,int x,int y,int v)
{
    if(lo>y||hi<x)return ;
    if(lo>=x&&hi<=y)
    {
        tree[pos]=v*(hi-lo+1);
        prop[pos]=v;
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    push(pos,lo,hi);
    update(left,lo,mid,x,y,v);
    update(right,mid+1,hi,x,y,v);
    tree[pos]=tree[left]+tree[right];
}

int query(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return 0;
    if(lo==x&&hi==y)
    {
        return prop[pos];
    }
    push(pos,lo,hi);
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    int p1=query(left,lo,mid,x,y);
    int p2=query(right,mid+1,hi,x,y);
    return p1+p2;
}
int main()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        memset(prop,-1,sizeof(prop));
       // memset(tree,0,sizeof(tree));
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            update(0,0,2*mx,a,b,i);
        }
        set<int >s;
        for(int i=1;i<=2*q;i++)
        {
            int k=query(0,0,2*mx,i,i);
            if(k>0)
            s.insert(k);
        }
       printf("Case %d: %d\n",t,s.size());
    }
}
