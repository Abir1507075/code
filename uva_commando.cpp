#include<bits/stdc++.h>
using namespace std;
#define maxi 100000000

int edge[500][500];


int main(){
    int tst,t=0;
    cin>>tst;
    while(tst--){
        t++;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                edge[i][j]=maxi;
            }
        }
        for(int i=0;i<n;i++){
            edge[i][i]=0;
        }

        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            edge[a][b]=1;
            edge[b][a]=1;
        }
        int s,d;
        cin>>s>>d;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if((edge[s][i]!=maxi and edge[i][d] != maxi)){
                res=max(res,edge[s][i]+edge[i][d]);
            }
        }
        printf("Case %d: %d\n",t,res);
    }

}
