#include<bits/stdc++.h>
using namespace std;

#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

#define ll long long
#define lim 100005
#define mod 1000000007


ll bit[lim+10];


void update(int idx,int val,int n){
    while(idx<=n){
        bit[idx]+=val;
        bit[idx]%=mod;
        idx+=(idx&(-idx));
    }
}

ll query(int idx){
    ll sum=0;
    while(idx>0){
        sum+=bit[idx];
        sum%=mod;
        idx-=(idx&(-idx));
    }
    return sum%mod;
}

int arr[lim+10];


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
        }
        update(1,1,n);
        for(int i=2;i<=n;i++){
            ll temp=query(i-1)-query(i-2);
            if(arr[i]>arr[i-1]){
                update(i,temp+1,n);
            }
        }
        ll res=0;
        for(int i=1;i<=n;i++){
            res+=query(i);
            res%=mod;
        }
        printf("Case %d: %lld\n",t,res);
        for(int i=0;i<lim;i++){
            bit[i]=0;
        }
    }
}
