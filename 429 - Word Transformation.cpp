#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lim 300000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
vector<int>edge[1000];
int vis[500];
int dis[500];
void bfs(int src){
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    queue<int>q;
    q.push(src);
    dis[src]=0;
    vis[src]=1;
    while(!q.empty()){
        int h=q.front();
        q.pop();
        for(int i=0;i<edge[h].size();i++){
            int u=edge[h][i];
            if(!vis[u]){
                vis[u]=1;
                dis[u]=dis[h]+1;
                q.push(u);
            }
        }
    }
}

int main(){
    int tst,t=0;
    cin>>tst;
    string s;
    getline(cin,s);
    while(tst--){
        t++;
        if(t!=1)cout<<endl;
        string arr[500];
        int id=0;
        map<string,int>mp;
        while(1){
            cin>>s;
            if(s=="*")break;
            mp[s] = id ;
            arr[id++] = s ;

        }

        for(int i=0;i<id;i++){
            for(int j=i+1;j<id;j++){
                if(arr[i].size()!=arr[j].size())continue;
                int cnt=0;
                for(int k=0;k<arr[i].size();k++){
                    if(arr[i][k]!=arr[j][k])cnt++;
                }
                if(cnt==1){
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        getchar();
        while(1){
            getline(cin,s);
            if( s == "")break;

            string t[10];
            int f=0;
            for(int i=0,j=0;i<s.size();i++){
                if(s[i]==' '){
                    t[j]=s.substr(f,i);
                    f=i+1;
                    j++;
                    continue;
                }
            }
            t[1]=s.substr(f,s.size());
            //cout<<t[0]<<" "<<t[1]<<endl;

            int src=mp[t[0]];
            int des=mp[t[1]];
            bfs(src);
            int res=dis[des]-dis[src];
            cout<<t[0]<<" "<<t[1]<<" "<<res<<endl;
        }
        for(int i=0;i<id;i++)edge[i].clear();
    }
}
