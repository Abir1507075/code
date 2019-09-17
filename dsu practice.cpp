#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 500005

int n,m;
vector<int>edge[lim+10];
string s;
int st[lim+10];
int ed[lim+10];
int T;

void dfs(int src,int p){
    st[src]=++T;
    for(auto u:edge[src]){
        if(u!=p){
            dfs(u,src);
        }
    }
}




int main(){
    cin>>n>>m;
    for(int i=2;i<n;i++){
        int a;
        cin>>a;
        edge[a].push_back(i);
    }
    cin>>s;

    while(m--){
        int a,b;
        cin>>a>>b;

    }
}
