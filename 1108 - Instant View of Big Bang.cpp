
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000000
class node
{
    public:
    int a,b,c;
    node():a(0),b(0),c(0){}
    node(int a,int b,int c):a(a),b(b),c(c){}
};
int dis[100005];
vector<int>v[100005],ans;
bool flag[100005];

void dfs(int x)
{
    if(flag[x])return;
    flag[x]=true;
    ans.push_back(x);
    for(int i=0;i<v[x].size();i++)
    {
        int h=v[x][i];
        if(!flag[h])dfs(h);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        node arr[m+5];
        for(int i=0;i<n;i++)
        {
            dis[i]=mx;
            v[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            arr[i]=node(b,a,c);
            v[b].push_back(a);
        }

        dis[0]=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(dis[arr[j].a]+arr[j].c<dis[arr[j].b])
                {
                    dis[arr[j].b]=dis[arr[j].a]+arr[j].c;
                }
            }
        }

        bool flag2=false;
        for(int j=1;j<=m;j++)
        {
            if(dis[arr[j].a]+arr[j].c<dis[arr[j].b])
            {
                flag2=true;
                if(!flag[arr[j].b])dfs(arr[j].b);
            }
        }
        if(flag2)
        {
            printf("Case %d: ",t);
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size()-1;i++)
            {
                printf("%d ",ans[i]);
            }
            printf("%d",ans[ans.size()-1]);
            printf("\n");
        }
        else printf("Case %d: impossible\n",t);
        memset(flag,false,sizeof(flag));
        ans.clear();

    }
}
