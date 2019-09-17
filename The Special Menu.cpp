#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[100];
ll dp[65][65];

ll call(int i,int j){
    if(i==j)return 1;
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    ll ret=0;
    if(s[i]==s[j])ret += call(i+1,j-1) + 1;
    ret += call(i,j-1) + call(i+1,j) - call(i+1,j-1) ;
    return dp[i][j]=ret;
}


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;

        scanf("%s",s);
        int sz=strlen(s);
        for(int i=0;i<=60;i++)
            for(int j=0;j<=60;j++)
                dp[i][j]=-1;
        ll res=call(0,sz-1);
        printf("Case %d: %lld\n",t,res);
    }
}
