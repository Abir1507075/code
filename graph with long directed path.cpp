#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 100005
vector<int>edge[lim+10];
map<pair<int,int> ,int >mp;

int vis[lim+10];
int col[lim+10];

int dfs(int src,int dir){
    vis[src]=1;
    col[src]=dir;
    int ret=1;
    for(int i=0;i<edge[src].size();i++){
        int u=edge[src][i];
        if(vis[u]==0){
            if(dir==1){
                mp[make_pair(src,u)]=2;
            }
            else mp[make_pair(src,u)]=3;
            ret&=dfs(u,3-dir);
        }
        else if (vis[u]==1){
            if(col[u]==3-dir){
                ret&=1;
            }
            else{
                ret&=0;
            }
        }
    }
    vis[src]=2;
    return ret;
}


int main(){
    int n,m;
    cin>>n>>m;
    pair<int,int>p[m+10];
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        p[i]=make_pair(a,b);
        edge[a].push_back(b);
        mp[make_pair(a,b)]=1;
    }
    int ans=dfs(1,1);
    if(ans!=0){
        cout<<"YES"<<endl;
        for(int i=0;i<m;i++){
            if(mp[p[i]]==2)cout<<"0";
            else cout<<"1";
        }
    }
    else{
        cout<<"NO"<<endl;
    }

}
