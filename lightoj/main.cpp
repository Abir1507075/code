#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 40000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define md (1e9) + 7
#define pi acos(-1)

string arr[lim+10][5];
int n;
vector<int>edge[30];
map< string , int > dis,vis;


bool check(string s, string t,int id,int i){
    int st=t.size();
    for(int j=0;j<arr[i][id].size();j++){
        if(arr[i][id][j]==s[id]){
            //cout<<arr[i][id]<<" "<<s[id]<<endl;
            return 1;
        }
    }

    return 0;
}

bool loop(string s){
    bool f=0;
    for(int i=0;i<n;i++){
        bool r=1;
        for(int j=0;j<3;j++){
            r&=check(s,arr[i][j],j,i);
        }
        f|=r;
    }
    return f;
}


bool bfs(string src,string des){
    if(loop(src))return 0;
    queue< string > q;
    q.push(src);
    dis[src] = 0 ;
    while(!q.empty()){
        string h = q.front();
        q.pop();
        //cout<<h<<endl;
        if(h==des)return 1;
        int arr[4];
        for(int i=0;i<3;i++){
            arr[i]=h[i]-'a';
        }

        for(int i=0;i<3;i++){
            for(int j=0;j<edge[arr[i]].size();j++){
                int u=edge[arr[i]][j];
                string k = h ;
                k[i] = u + 'a' ;
                if(!vis[k]){
                    vis[k]=1;
                    if(!loop(k)){
                        dis[k]=dis[h]+1;
                        q.push(k);
                    }
                }
            }
        }
    }
    return 0;
}


void Clear(){
    dis.clear();
    vis.clear();
}


void init(){
    edge[0].push_back(1);
    edge[0].push_back(25);
    for(int i=1;i<25;i++){
        edge[i].push_back(i+1);
        edge[i].push_back(i-1);
    }
    edge[25].push_back(24);
    edge[25].push_back(0);
}

int main(){
    int tst,tt=0;
    init();
    scanf("%d",&tst);
    while(tst--){
        tt++;
        string s,t;
        cin>>s>>t;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>arr[i][j];
            }
        }
        Clear();
        bool res=bfs(s,t);
        if(res){
            printf("Case %d: %d\n",tt,dis[t]);
        }
        else {
            printf("Case %d: -1\n",tt);
        }
    }
}
