#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define lim 300005
#define ll long long
ll par[lim+10];

ll findpar(int n){
    if(n==par[n])return n;
    else return par[n] = findpar(par[n]);
}


int  Union(int a,int b){
    int x=findpar(a);
    int y=findpar(b);
    if(x!=y){
        par[y]=x;
        return 1;
    }
    return 0;
}

int main(){
    ll n,m;
    while(1){
        cin>>n>>m;
        if(n==0 and m==0 )break;
        for(int i=1;i<=n+10;i++){
            par[i]=i;
        }
        ll res=0;
        vector< pair< ll , pair< ll , ll > > >road;
        for(int i=0;i<m;i++){
            ll a,b,c;
            cin>>a>>b>>c;
            res+=c;
            a++,b++;
            road.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(road.begin(),road.end());
        ll node=0;
        for(int i=0;i<m;i++){
            if( node == n -1 )break;
            int k = Union( road[i].second.first , road[i].second.second );
            if( k == 1 ){
                node ++;
                res -= road[i].first;
            }
        }
        cout<<res<<endl;
    }
}
