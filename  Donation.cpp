#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int src,des,cost;
};
bool cmp(node p, node q)
{
    if(p.cost<q.cost)return true;
    else return false;
}
int arr[100][100];
int par[105];
int find_par(int n)
{
    if(par[n]==n)return n;
    else return find_par(par[n]);
}

int main()
{
    int tst;
    cin>>tst;
    for(int t=1;t<=tst;t++)
    {
        int n;
        cin>>n;
        int cnt=0;
        vector<node>a;
        for(int i=1;i<=n;i++)
        {
            par[i]=i;
            for(int j=1;j<=n;j++)
            {
                cin>>arr[i][j];
                cnt+=arr[i][j];
                if(i==j)continue;
                node temp;
                temp.src=i;
                temp.des=j;
                temp.cost=arr[i][j];
                a.push_back(temp);
            }
        }
        sort(a.begin(),a.end(),cmp);
        int edge=0,cost=0;
        for(int i=0;i<a.size();i++)
        {
            int x=find_par(a[i].src);
            int y=find_par(a[i].des);
            if(x==y or a[i].cost==0)continue;
            par[x]=y;
            edge++;
            cost+=a[i].cost;
        }
        cout<<"Case "<<t<<": ";
        if(edge==n-1)cout<<cnt-cost<<endl;
        else cout<<"-1"<<endl;
        memset(par,0,sizeof par);
        a.clear();
    }
}
