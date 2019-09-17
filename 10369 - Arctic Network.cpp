#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define ll long long
#define lim 300000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
ll par[lim+10];

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


ll dis(int x,int y,int a ,int b){
    return (x-a)*(x-a) + (y-b)*(y-b);
}


int main(){
    int tst,t=0;
    cin>>tst;
    while(tst--){
        t++;
        int s,n;
        cin>>s>>n;
        for(int i=1;i<=(n*n);i++){
            par[i]=i;
        }
        pair<int,int>arr[n+10];
        vector< pair < ll , pair < ll , ll > > >road;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            arr[i]=make_pair(x,y);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll d = dis(arr[i].first,arr[i].second,arr[j].first,arr[j].second);
                road.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        sort(road.begin(),road.end());
        int path=0;
        double cost=0.0;

        for(int i=0;i<road.size();i++){
            if(path== n-s )break;
            int k = Union(road[i].second.first,road[i].second.second);
            if( k == 1 ){
                path++;
                cost = max(cost,sqrt(road[i].first));
            }
        }

        printf("%.2f\n",cost);
    }
}
