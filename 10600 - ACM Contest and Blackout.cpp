#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define ll long long
#define lim 300000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
ll par[1000];

int findpar(int n){
    if(n==par[n])return n;
    else return par[n]=findpar(par[n]);
}

int Union(int a,int b){
    int x=findpar(a);
    int y=findpar(b);
    if(x!=y){
        if(x<y)par[y]=x;
        else par[x]=y;
        return 1;
    }
    return 0;
}


int main(){

    int tst;
    cin>>tst;
    while(tst--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        vector< pair < ll , pair < ll , ll > > >road;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            road.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(road.begin(),road.end());
        vector<int>res,taken;
        int node=0,cost=0;
        for(int j=0;j<m;j++){
            if(node==n-1)break;
            int k  = Union(road[j].second.first,road[j].second.second);
            if( k == 1){
                node++;
                taken.push_back(j);
                cost+=road[j].first;
            }
        }
        if(node==n-1)res.push_back(cost);

        for(int i=0;i<taken.size();i++){
            for(int j=0;j<=n;j++){
                par[j]=j;
            }
            cost=0,node=0;
            for(int j=0;j<m;j++){
                if(taken[i]==j)continue;
                if(node==n-1)break;
                int k  = Union(road[j].second.first,road[j].second.second);
                if( k == 1){
                    node++;
                    cost+=road[j].first;
                }
            }

            if(node==n-1)res.push_back(cost);
        }

        sort(res.begin(),res.end());
        cout<<res[0]<<" "<<res[1]<<endl;
    }
}
