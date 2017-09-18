#include<bits/stdc++.h>

using namespace std;
int n,cap,ans;
int dp[1005][50],cost[1005],weight[1005];
int knapsack(int i,int w)
{
    if(i==n+1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int cost1=0,cost2=0;
    if(w+weight[i]<=cap)cost1=knapsack(i+1,w+weight[i])+cost[i];
    cost2=knapsack(i+1,w);
    return dp[i][w]=max(cost1,cost2);
}
int main()
{
   //freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tc;
    cin>>tc;
    while(tc--)
    {
            cin>>n;
            ans=0;
            for(int i=1; i<=n; i++)
            {
                cin>>cost[i]>>weight[i];
            }
            int g;
            cin>>g;
            for(int i=0; i<g; i++)
            {
                memset(dp,-1,sizeof(dp));
                cin>>cap;
                ans=ans+knapsack(1,0);
            }
            cout<<ans<<endl;;
    }
}

