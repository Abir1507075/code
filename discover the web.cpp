#include<bits/stdc++.h>
using namespace std;
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

#define ll long long
#define lim 200005

int col[3*lim+10];




void init(int pos,int lo,int hi){
    if(lo==hi){
        col[lo]=0;
        return;
    }
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    init(left,lo,mid);
    init(right,mid+1,hi);
}

void push(int pos,int lo,int hi){
    if(col[pos]==0)return;
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    col[left]=col[right]=col[pos];
    col[pos]=0;
}


void update(int pos,int lo,int hi,int x,int y,int val){
    if(lo>y||hi<x){
            return ;
    }
    if(lo>=x&&hi<=y){
        col[pos]=val;
        return;
    }
    push(pos,lo,hi);
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    update(left,lo,mid,x,y,val);
    update(right,mid+1,hi,x,y,val);
}

int query(int pos,int lo,int hi,int x,int y){
    if(lo>y||hi<x){
        return 0;
    }
    if(lo>=x&&hi<=y){
        return col[pos];
    }
    push(pos,lo,hi);
    int mid=(lo+hi)/2;
    int left=2*pos+1;
    int right=left+1;
    int p1=query(left,lo,mid,x,y);
    int p2=query(right,mid+1,hi,x,y);
    if(p1==0)return p2;
    else return p1;
}



int cnt[2*lim+10];



int main(){
    fin;
    fout;
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        int n;
        scanf("%d",&n);

        for(int i=0;i<2*lim;i++){
            cnt[i]=0;
        }
        for(int i=0;i<3*lim;i++){
            col[i]=0;
        }

        init(0,0,2*n-1);
        for(int i=1;i<=n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            update(0,0,2*n,a,b,i);
        }
        int res=0;
        for(int i=0;i<=2*n;i++){
            int temp=query(0,0,2*n,i,i);
            //cout<<temp<<endl;
            if(temp==0)continue;
            cnt[temp]++;
            if(cnt[temp]==1)res++;
        }
        printf("Case %d: %d\n",t,res);
    }
}
