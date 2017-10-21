#include<bits/stdc++.h>
using namespace std;
vector<int>v[100000];

int flag[100000];
int color[100000];

int ans1;
int ans2;
void bfs(int src)
{
    int arr[3];
    for(int i=0;i<3;i++)arr[i]=0;
    queue<int>q;
    q.push(src);
    color[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++)
        {
            int h=v[u][i];
            if(!flag[h])
            {
                flag[h]=1;
                color[h]=3-color[u];
                arr[color[h]]++;
                q.push(h);
            }
        }
    }
    ans1=arr[1];
    ans2=arr[2];
}


int main()
{
    int tst;
    cin>>tst;
    for(int t=1;t<=tst;t++)
    {
        int n;
        scanf("%d",&n);

        vector<int>s;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            mp[a]++;
            mp[b]++;
            if(mp[a]==1)s.push_back(a);
            if(mp[b]==1)s.push_back(b);
        }
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            ans1=0;
            ans2=0;
            if(!flag[s[i]])
            bfs(s[i]);

            res+=max(ans1,ans2);
        }
        printf("Case %d: %d\n",t,res);
        memset(flag,0,sizeof flag);
        memset(color,0,sizeof color);
        for(int i=0;i<s.size();i++)v[s[i]].clear();

    }
}
