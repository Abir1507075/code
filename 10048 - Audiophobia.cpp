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
vector< pair < int,int > >edge[1000];
int vis[200];
int dis[200][200];
void bfs(int src){
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int i=0;i<edge[h].size();i++){
            int u=edge[h][i].second;
            if(!vis[u]){
                dis[src][u] = max(dis[src][h],edge[h][i].first);
                vis[u]=1;
                q.push(u);
            }
        }
    }
}

int main(){
    int c,s,q,t=0;;
    while(1){
        t++;
        cin>>c>>s>>q;
        if(c==0 and s==0 and q==0)break;
        if(t!=1)cout<<endl;
        for(int i=0;i<=c;i++){
            par[i] = i ;
        }
        vector< pair < ll , pair < ll , ll > > >road;
        for(int i=0;i<s;i++){
            int a,b,cost;
            cin>>a>>b>>cost;
            road.push_back(make_pair(cost,make_pair(a,b)));
        }
        sort(road.begin(),road.end());
        int node=0;
        for(int i=0;i<s;i++){
            if(node==c-1)break;
            int k = Union(road[i].second.first,road[i].second.second);
            if(k == 1 ){
                node++;
                edge[road[i].second.first].push_back(make_pair(road[i].first,road[i].second.second));
                edge[road[i].second.second].push_back(make_pair(road[i].first,road[i].second.first));
            }
        }
        for(int i=0;i<=c;i++){
            for(int j=0;j<=c;j++){
                dis[i][j]=0;
            }
        }
        for(int i=1;i<=c;i++){
            //cout<<i<<endl;
            bfs(i);
        }
        printf("Case #%d\n",t);

        for(int i=0;i<q;i++){
            int a,b;
            cin>>a>>b;
            int x=findpar(a);
            int y=findpar(b);
            if(x!=y){
                printf("no path\n");
            }
            else printf("%d\n",dis[a][b]);
        }
        for(int i=0;i<=c;i++){
            edge[i].clear();
        }

    }
}
