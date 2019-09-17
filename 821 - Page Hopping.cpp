#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
int edge[150][150];


int main(){
    int a,b,t=0;
    while(1){
        t++;
        cin>>a>>b;
        if(a==0 and b==0)break;
        set<int>st;
        for(int i=1;i<105;i++){
            for(int j=1;j<105;j++){
                edge[i][j]=inf;
            }
        }
        for(int i=1;i<105;i++){
            edge[i][i]=0;
        }
        while(1){
            st.insert(a);
            st.insert(b);
            edge[a][b]=1;
            cin>>a>>b;
            if(a==0 and b==0){
                for(int k=1;k<105;k++){
                    for(int i=1;i<105;i++){
                        for(int j=1;j<105;j++){
                            edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
                        }
                    }
                }
                double res=0,tst=st.size();
                for(int i=1;i<105;i++){
                    for(int j=1;j<105;j++){
                        if(edge[i][j]<inf){
                            res+=edge[i][j];
                        }
                    }
                }
                tst=((tst*(tst-1)));
                res/=tst;
                printf("Case %d: average length between pages = %.3f clicks\n",t,res);
                break;
                st.clear();
            }
            st.insert(a);
            st.insert(b);
            edge[a][b]=1;
        }

    }
}
