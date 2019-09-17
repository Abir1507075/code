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
        par[y]=x;
        return 1;
    }
    return 0;
}

ll dis(int x,int y,int a ,int b){
    return (x-a)*(x-a) + (y-b) * (y-b) ;
}

int main(){
    int tst,t=0;
    cin>>tst;
    while(tst--){
        t++;
        int n,r;
        cin>>n>>r;
        r*=r;
        for(int i=1;i<=n*n+1;i++){
            par[i]=i;
        }
        pair<int,int>arr[n+10];
        vector< pair < ll , pair < ll , ll > > > road;
        for(int i=1;i<=n;i++){
            cin>>arr[i].first>>arr[i].second;
            arr[i].first+=10000;
            arr[i].second+=10000;

        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll d = dis(arr[i].first,arr[i].second,arr[j].first,arr[j].second);
                road.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        sort(road.begin(),road.end());
        double res1=0,res2=0;
        int f=0;
        for(int i=0;i<road.size();i++){
            int k = Union(road[i].second.first,road[i].second.second);
            if( k == 1 ){
                if(road[i].first<=r){
                    res1+=sqrt(road[i].first);
                }
                else{
                    f++;
                    res2+=sqrt(road[i].first);
                }
            }
        }
        ll o=round(res1);
        ll p=round(res2);
        printf("Case #%d: %d %lld %lld\n",t,f+1,o,p);

    }
}
