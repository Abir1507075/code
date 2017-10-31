#include<bits/stdc++.h>
using namespace std;

int arr[20];
int cnt[20];
int n;
int hold[100][100];
stack<int>s;
bool valid(int x)
{
    //cout<<x<<endl;
    int prime[20]={2,3,5,7,11,13,17,19,23,29,31,37,41};
    for(int i=0;i<13;i++)
    {
        if(x==prime[i])return true;
    }
    return false;
}
int track;
int all()
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {

        if(cnt[i]==1)sum++;
    }
    return sum;
}
void dfs(int src){
    track++;
    if(track==n)cout<<src;
    else cout<<src<<" ";
    for(int i=1;i<=n;i++)
    {
        if(hold[src][i]==1)dfs(i);
    }
}
void backt(int src)
{
    if(all()>=n-1)
    {
        if(valid(src+1))
        {
            track=0;
            dfs(1);
            cout<<endl;
        }
        return ;
    }

    for(int i=2;i<=n;i++)
    {
        if(cnt[i]==0 and valid(src+i))
        {
            //cout<<src<<" "<< i<<endl;
            cnt[i]=1;
            hold[src][i]=1;
            backt(i);

            cnt[i]=0;
            hold[src][i]=0;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tst=0;
    while(cin>>n)
    {
        tst++;
        if(tst!=1)cout<<endl;
        cout<<"Case "<<tst<<":"<<endl;
        backt(1);
        memset(hold,0,sizeof hold);
        memset(cnt,0,sizeof cnt);
    }


}
