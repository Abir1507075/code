#include<bits/stdc++.h>
using namespace std;
#define mx 100000000
class node
{
    public:
    int a,b,c;
};

int cube(int a,int b)
{
    int k=(b-a)*(b-a)*(b-a);
    return k;
}
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int tst;
    cin>>tst;
    for(int t=1;t<=tst;t++)
    {
        int n;
        cin>>n;
        node cost[500000];
        int dis[500000];
        int c[500000];
        for(int i=1;i<=n;i++)
        {
            cin>>dis[i];
            c[i]=mx;
        }
        int e;
        cin>>e;
        for(int k=1;k<=e;k++)
        {
            int a,b;
            cin>>a>>b;
            int x=cube(dis[a],dis[b]);
            cost[k].a=a;
            cost[k].b=b;
            cost[k].c=x;
        }
        c[1]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=e;j++)
            {
                if(c[cost[j].a]+cost[j].c<c[cost[j].b]&&c[cost[j].a]!=mx)
                {
                    c[cost[j].b]=c[cost[j].a]+cost[j].c;
                }
            }
        }
        bool flag=false;
        for(int j=1;j<=e;j++)
        {
            if(c[cost[j].a]+cost[j].c <c[cost[j].b] &&c[cost[j].a]!=mx)
            {
                c[cost[j].b]=-mx;
            }
        }
        printf("Case %d:\n",t);
        int q;
        cin>>q;
        while(q--)
        {
            int p;
            cin>>p;
            if(c[p]<3||c[p]==mx)cout<<"?"<<endl;
            else cout<<c[p]<<endl;

        }

    }
}
