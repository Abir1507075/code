#include<bits/stdc++.h>
using namespace std;


int n,d;

int arr[200000];
int tree[3*200000];
int maxval[3*200000];
int minval[3*200000];
void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
       maxval[pos]=arr[lo];
       minval[pos]=arr[lo];
       return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
    minval[pos]=min(minval[left],minval[right]);
    maxval[pos]=max(maxval[left],maxval[right]);
    return;
}

int minq(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return 10000000000;
    if(lo>=x&&hi<=y)
    {
        return minval[pos];
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    int p1=minq(left,lo,mid,x,y);
    int p2=minq(right,mid+1,hi,x,y);
    return min(p1,p2);
}
int maxq(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return 0;
    if(lo>=x&&hi<=y)
    {
        return maxval[pos];
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(lo+hi)/2;
    int p1=maxq(left,lo,mid,x,y);
    int p2=maxq(right,mid+1,hi,x,y);
    return max(p1,p2);
}

int main()
{
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        scanf("%d %d",&n,&d);

        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build(0,0,n-1);
       // cout<<minq(0,0,n-1,3,5)<<endl;;
        int temp=0;
        for(int i=0;i<n-d;i++)
        {

            //cout<<maxq(0,0,n-1,i,i+d)<<" "<<minq(0,0,n-1,i,i+d)<<endl;
            temp=max(temp,(maxq(0,0,n-1,i,i+d-1)-minq(0,0,n-1,i,i+d-1)));
           // cout<<temp<<endl;
        }
        printf("Case %d: %d\n",t,temp);
        memset(minval,0,sizeof minval);
        memset(maxval,0,sizeof maxval);
    }
}
