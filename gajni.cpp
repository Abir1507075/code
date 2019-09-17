#include<bits/stdc++.h>
using namespace std;

#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

#define ll long long
#define lim 100005
#define mx 500000000



int arr[lim+100];
int mini[3*lim+10];
int maxi[3*lim+10];

void init(int pos,int lo,int hi){
    if(lo==hi){
        mini[pos]=arr[lo];
        maxi[pos]=arr[lo];
        return;
    }
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    init(left,lo,mid);
    init(right,mid+1,hi);
    mini[pos]=min(mini[left],mini[right]);
    maxi[pos]=max(maxi[left],maxi[right]);
}


int mxquery(int pos,int lo,int hi,int x,int y){
    if(lo>y||hi<x)return -100000000;
    if(lo>=x&&hi<=y){
        return maxi[pos];
    }
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    int p1=mxquery(left,lo,mid,x,y);
    int p2=mxquery(right,mid+1,hi,x,y);
    return max(p1,p2);
}

int minquery(int pos,int lo,int hi,int x,int y){
    if(lo>y||hi<x)return mx;
    if(lo>=x&&hi<=y){
        return mini[pos];
    }
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    int p1=minquery(left,lo,mid,x,y);
    int p2=minquery(right,mid+1,hi,x,y);
    return min(p1,p2);
}

int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        for(int i=0;i<3*lim;i++){
            maxi[i]=-100000000;
            mini[i]=mx;
        }
        init(0,0,n-1);
        int res=0;
        for(int i=0;i<=n-m;i++){
            int l=i;
            int r=i+m-1;
            int temp=mxquery(0,0,n-1,l,r)-minquery(0,0,n-1,l,r);
            res=max(res,temp);
        }
        printf("Case %d: %d\n",t,res);
    }
}
