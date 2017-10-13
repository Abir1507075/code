
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000000
class node
{
    public:
    int a,b,c;
};
int dis[10005];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int city,road,profit;
        scanf("%d %d %d",&city,&road,&profit);
        for(int i=0;i<city;i++)dis[i]=mx;
        node arr[road+5];
        for(int i=1;i<=road;i++)
        {
            int a,b,c,d;
            scanf("%d %d %d %d",&a,&b,&c,&d);
            arr[i].a=a;
            arr[i].b=b;
            arr[i].c=(profit*d)-c;
        }
        dis[0]=0;
        for(int i=0;i<city-1;i++)
        {
            for(int j=1;j<=road;j++)
            {
                if(dis[arr[j].a]+arr[j].c<dis[arr[j].b])
                {
                    dis[arr[j].b]=dis[arr[j].a]+arr[j].c;
                }
            }
        }
        bool flag=false;
        for(int j=1;j<=road;j++)
        {
            if(dis[arr[j].a]+arr[j].c<dis[arr[j].b])
            {
                flag=true;
                break;
            }
        }
        if(flag)printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
    }
}
