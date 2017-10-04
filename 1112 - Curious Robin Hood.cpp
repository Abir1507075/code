#include<bits/stdc++.h>
using namespace std;
int a[100005];
int tree[3*100005];
void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        tree[pos]=a[lo];
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    build(left,lo,(lo+hi)/2);
    build(right,((lo+hi)/2)+1,hi);
    tree[pos]=tree[left]+tree[right];
}

void update(int pos,int lo,int hi,int x,int y,int c)
{
    if(lo>y||hi<x)return;
    if(lo==x&&hi==x)
    {
        tree[pos]=c;
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    update(left,lo,(lo+hi)/2,x,y,c);
    update(right,((lo+hi)/2)+1,hi,x,y,c);
    tree[pos]=tree[left]+tree[right];
   // cout<<tree[pos]<<' '<<pos<<endl;

}
int query(int pos,int lo,int hi, int x,int y)
{
    if(lo>y||hi<x)return 0;
    if(lo>=x&&hi<=y)
    {
        return tree[pos];
    }
    int left=pos*2+1;
    int right=left+1;
    int p1=query(left,lo,(hi+lo)/2,x,y);
    int p2=query(right,((hi+lo)/2)+1,hi,x,y);
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
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        build(0,0,n-1);
        printf("Case %d:\n",t);
        for(int i=0;i<q;i++)
        {
            int k;
            int x,y,z;
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&x);
                printf("%d\n",a[x]);
                a[x]=0;
                update(0,0,n-1,x,x,0);
            }
            else if(k==2)
            {
                scanf("%d %d",&x,&y);
                update(0,0,n-1,x,x,y+a[x]);
                a[x]=a[x]+y;
            }
            else
            {
                scanf("%d %d",&x,&z);
                printf("%d\n",query(0,0,n-1,x,z));
            }
            //cout<<tree[0]<<endl;
        }
    }
}
