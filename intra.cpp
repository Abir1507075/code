#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 100005
bool mark[lim+1000];
int prime[lim+1000];
int sz;


void seive(){
    for(int i=3;i<=sqrt(lim);i+=2){
        if(!mark[i]){
            for(int j=i*i;j<=lim;j+=(2*i))mark[j]=true;
        }
    }
    prime[sz++]=2;
    for(int i=3;i<=lim;i+=2){
        if(!mark[i]){
            prime[sz++]=i;
        }
    }
}

int divisor(int n){
    ll res=1;
    for(int i=0;i<sz;i++){
        if(prime[i]*prime[i]>=n)break;
        int cnt=0;
        while(n%prime[i]==0){
            cnt++;
            n/=prime[i];
        }
        res*=(cnt+1);
    }
    if(n>1)res*=2;
    return res;
}

ll divi[lim+10];


void pre(){
    for(int i=0;i<=lim;i++){
        divi[i]=divisor(i);
    }
}

int main(){
    seive();
    pre();
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        int n,q;
        scanf("%d %d",&n,&q);
        int arr[q+10];
        ll maxi=0,mini=1000000000000;
        int tot=n;
        for(int i=0;i<q;i++){
            scanf("%d",&arr[i]);
            ll temp=divi[arr[i]-1]+div[arr[i]];
            temp=2*temp + 1;
            if(temp<=tot){
                tot-=temp;
            }
            else{
                tot=0;
                temp=tot;
            }
            maxi=max(maxi,temp);
            mini=min(mini,temp);
        }
        if(tot!=0){

        }
        int ans1,ans2;

        printf("Case %d: %d %d\n",t,ans1,ans2);
    }
}
