#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int a,b,c;
};

int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
        node cost[5000];
        for(int i=0;i<e;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cost[i].a=a;
            cost[i].b=b;
            cost[i].c=c;
        }
        int dis[5000];
        for(int i=0;i<n;i++)dis[i]=100000000;
        dis[0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<e;j++)
            {
                if(dis[cost[j].a]+cost[j].c<dis[cost[j].b])
                {
                    dis[cost[j].b]=dis[cost[j].a]+cost[j].c;
                }
            }
        }
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<e;j++)
            {
                if(dis[cost[j].a]+cost[j].c<dis[cost[j].b])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        if(flag)cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;

    }

}
