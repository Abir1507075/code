
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int coin[60];
ll dp[30][10005];
ll make_change(int i,int amount)
{
    if(i>=21)
    {
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    ll ret1=0,ret2=0;
    if(amount-coin[i]>=0) ret1=make_change(i,amount-coin[i]);
    ret2=make_change(i+1,amount);
    return dp[i][amount]=ret1+ret2;
}

int main()
{
    for(int i=1;i<=21;i++)
    {
        coin[i-1]=i*i*i;
    }

    int amount;
    memset(dp,-1,sizeof(dp));
    while(cin>>amount)
    {
        cout<<make_change(0,amount)<<endl;
    }
}

