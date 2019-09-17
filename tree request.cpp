#include<bits/stdc++.h>
using namespace std;
#define lim 600005
int n,m,t;
char s[lim+10];
vector<int>edge[lim+10];
vector< pair<int,int> >query[lim+10];

int sz[lim+10];
void getsz(int v,int p){
    sz[v]=1;
    for(int i=0;i<edge[v].size();i++){
        int u=edge[v][i];
        if(u!=p){
            getsz(u,v);
            sz[v]+=sz[u];
        }
    }
}

int big[lim+10];
int cnt[lim+10][30];
int ans[lim+10];

void add(int v,int p,int lvl,int x){
    cnt[lvl][s[v-1]-'a']+=x;
    for(int i=0;i<edge[v].size();i++){
        int u=edge[v][i];
        if(u!=p and !big[u]){
            add(u,v,lvl+1,x);
        }
    }
}
int ispalindrome(int lvl){
    int ans=0;
    for(int i=0;i<26;i++){
        ans+= (cnt[lvl][i]%2);
    }
    if(ans>1)return 0;
    else return 1;

}
void dfs(int v,int p,int lvl,int keep){
    int mx=-1,bigchild=-1;
    for(int i=0;i<edge[v].size();i++){
        int u=edge[v][i];
        if(u!=p and sz[u]> mx ){
            mx=sz[u];
            bigchild=u;
        }
    }
    for(int i=0;i<edge[v].size();i++){
        int u=edge[v][i];
        if(u!=p and u!=bigchild){
            dfs(u,v,lvl+1,0);
        }
    }
    if(bigchild!=-1){
        dfs(bigchild,v,lvl+1,1);
        big[bigchild]=1;
    }

    add(v,p,lvl,1);
    for(int i=0;i<query[v].size();i++){
        if(lvl>=query[v][i].first){
            ans[query[v][i].second]=1;
        }
        else{
            ans[query[v][i].second]=ispalindrome(query[v][i].first);
        }
    }

    if(bigchild!=-1){
        big[bigchild]=0;
    }
    if(keep==0){
        add(v,p,lvl,-1);
    }
}



int main(){
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++){
        scanf("%d",&t);
        edge[t].push_back(i);
    }
    scanf("%s",s);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        query[a].push_back(make_pair(b,i));
    }
    dfs(1,-1,1,0);
    for(int i=0;i<m;i++){
        if(ans[i]){
            printf("Yes\n");
        }
        else printf("No\n");
    }
}
