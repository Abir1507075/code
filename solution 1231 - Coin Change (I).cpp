
#include<bits/stdc++.h>

using namespace std;
int coin[60];
int cost[200];
int dp[60][2000];
int n,amount;
int make_change(int i,int amount)
{
    if(i>=n)
    {
        if(amount==0)return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)return dp[i][amount];
    int sum=0;
    for(int j=0;j<=cost[i] && amount-(j*coin[i])>=0;j++)
    {
        sum+=make_change(i+1,amount-(j*coin[i]));
        sum%=100000007;
    }
    return dp[i][amount]=sum;

}

int main()
{

    int tst;
    cin>>tst;
    for(int t=1;t<=tst;t++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>amount;
        for(int i=0;i<n;i++)
        {
            cin>>coin[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>cost[i];
        }
       cout<<"Case "<<t<<": "<<make_change(0,amount)<<endl;


    }
}

