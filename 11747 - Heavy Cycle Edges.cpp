#include<bits/stdc++.h>

using namespace std;
#define inf 100000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define lim 2000005
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
        if(x<y)par[y]=x;
        else par[x]=y;
        return 1;
    }
    return 0;
}

int main(){
    int n,m;
    while(1){
        cin>>n>>m;
        if(n==0 and m==0 )break;
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        vector< pair < ll , pair < ll , ll > > > road;
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            road.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(road.begin(),road.end());
        int flag=0;
        vector< ll >res;
        for(int i=0;i<m;i++){
            int k = Union( road[i].second.first,road[i].second.second );
            if( k==0 ){
                flag=1;
                res.push_back(road[i].first);
            }
        }
        if(!flag){
            cout<<"forest"<<endl;
        }
        else{
            for(int i=0;i<res.size()-1;i++){
                cout<<res[i]<<" ";
            }
            cout<<res[res.size()-1]<<endl;
        }
    }
}
