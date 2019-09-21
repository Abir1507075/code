#include<bits/stdc++.h>
using namespace std;
#define lim 2000
#define ll long long
int n;
int arr[lim+10];


ll dp[1005][1005][3];

ll call(int idx,int prof,int buy){
    if(idx==n-1){
        return 0;
    }
    if(dp[idx][prof][buy]!=-1)return dp[idx][prof][buy];
    ll ret=0;
    if(buy==1){
        for(int i=0;i<n;i++){
            int p = arr[i]-arr[idx];
            if(p>=prof){
                ret=max(ret,call(i,p,0)+p);
            }
        }
    }
    else if(buy==2){
        for(int i=idx+1;i<n;i++){
            int p = arr[i]-arr[idx];
            if(p>=prof){
                ret=max(ret,call(i,p,0)+p);
            }
            else break;
        }
    }
    else{
        for(int i=idx+1;i<n;i++){
            ret=max(ret,call(i,prof,2));
        }
    }
    return dp[idx][prof][buy]=ret;
}


int main(){
    int tst;
    scanf("%d",&tst);
    while(tst--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        memset(dp,-1,sizeof dp);
        ll res=call(0,0,1);
        cout<<res<<endl;
    }
}
