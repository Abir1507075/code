#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 1000005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define md 998244353

ll n;
vector<ll>v;
pair<ll,ll>p[lim+10];
vector< ll > store[lim+10],fun[lim+10];

ll dp[lim+10][5];
int sz;

ll call(int idx,int pos){
    if(idx==sz){
        return 0;
    }
    if(dp[idx][pos]!=-1)return dp[idx][pos];

    ll r1 = 0 ;
    if(pos==4){
        for(int i=0;i<fun[idx].size();i++){
            r1=max(r1,call(idx+1,i));
        }
    }
    else{
        for(int i=0;i<fun[idx-1].size();i++){
            if(i == pos )continue;
            for(int j=0;j<fun[idx].size();j++){
                r1=max(r1,call(idx+1,j)+abs( fun[idx][j] - fun[idx-1][i]));
            }
        }
    }
    return dp[idx][pos]=r1;
}



int main(){
    scanf("%lld",&n);

    for(int i=0;i<n;i++){
        scanf("%lld %lld",&p[i].first,&p[i].second);
    }
    sort(p,p+n);
    set<ll>st;
    for(int i=0;i<n;i++){
        st.insert(p[i].first);
    }
    map<ll,ll>mp;
    for(set<ll>::iterator it = st.begin();it!=st.end();it++){
        v.push_back(*it);
        mp[*it]=v.size()-1;
    }
    sz=v.size();
    for(int i=0;i<n;i++){
        store[mp[p[i].first]].push_back(p[i].second);
    }
    for(int i=0;i<sz;i++){
        int k=store[i].size();
        if(k==1){
            fun[i].push_back(store[i][0]);
            fun[i].push_back(store[i][0]);

        }
        else if (k==2){
            fun[i].push_back(store[i][0]);
            fun[i].push_back(store[i][1]);
        }
        else if (k==3){
            fun[i].push_back(store[i][0]);
            fun[i].push_back(store[i][1]);
            fun[i].push_back(store[i][k-1]);
        }
        else if (k>=4){
            fun[i].push_back(store[i][0]);
            fun[i].push_back(store[i][1]);
            fun[i].push_back(store[i][k-1]);
            fun[i].push_back(store[i][k-2]);
        }
    }
    memset(dp,-1,sizeof dp);
    ll ans = call(0,4);
    printf("%lld\n",ans);

}
