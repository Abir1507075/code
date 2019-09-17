#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 200000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);


int n,m,s,d;
vector<int>edge[lim];

int vis[lim];
int dis1[lim];
int dis2[lim];

int bfs(int flag,int src){
    queue<int>q;
    q.push(src);
    if(flag)dis1[src]=0;
    else dis2[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int h = q.front();
        q.pop();
        for(int i=0;i<edge[h].size();i++){
            int u = edge[h][i];
            if(!vis[u]){
                q.push(u);
                if(flag)dis1[u] = dis1[h] + 1 ;
                else dis2[u] = dis2[h] + 1 ;
                vis[u]=1;
             }
        }
    }
}


int main(){
    //fin;
    //fout;
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        memset(dis1,0,sizeof dis1);
        memset(dis2,0,sizeof dis2);
        memset(vis,0,sizeof vis);
        scanf("%d %d",&s,&d);
        bfs(1,s);
        memset(vis,0,sizeof vis);
        bfs(0,d);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dis1[i]+dis2[i]);
        }
        printf("Case %d: %d\n",t,ans);
        for(int i=0;i<n;i++){
            edge[i].clear();
        }
    }
}
