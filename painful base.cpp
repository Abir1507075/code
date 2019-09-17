#include<bits/stdc++.h>
using namespace std;
#define ll long long
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int arr[100];

ll dp[(1<<16)+100][25];
int sz;
int base,k;
ll call(int mask,int val){
    if(mask == ( 1 << sz ) - 1 ){
        if(val % k == 0 ) return 1;
        else return 0;
    }
    if(dp[mask][val] != -1 )return dp[mask][val] ;
    ll ret = 0 ;

    for(int i = 0 ; i < sz ; i++){
        if(!check(mask,i)){
            //cout<<((( val * base ) + arr[i] ) % k)<<endl;
            ret += call(Set(mask,i) , ( ( val * base ) + arr[i] ) % k ) ;
        }
    }
    return dp[mask][val] = ret;
}


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        scanf("%d %d",&base,&k);
        char s[100];
        scanf("%s",s);
        sz = strlen(s) ;

        for(int i=0;i<sz;i++){
            if(s[i]>='A'&&s[i]<='F')arr[i] = s[i] - 'A' + 10;
            else arr[i] = s[i] - '0' ;
        }
        memset(dp,-1,sizeof dp);
        ll res = call(0,0);
        printf("Case %d: %lld\n",t,res);


    }
}
