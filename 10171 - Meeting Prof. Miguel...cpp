#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
int edgeY[50][50];
int edgeM[50][50];

int main(){
    int n;
    while(1){
        cin>>n;
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                edgeY[i][j]=inf;
                edgeM[i][j]=inf;
            }
        }
        if(n==0)break;
        char a,b,c,d;
        int cost;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c>>d>>cost;
            if(a=='Y'){
                if(b=='U'){
                    edgeY[c-'A'][d-'A']=cost;
                }
                else{
                    edgeY[c-'A'][d-'A']=cost;
                    edgeY[d-'A'][c-'A']=cost;
                }
            }
            else{
                if(b=='U'){
                    edgeM[c-'A'][d-'A']=cost;
                }
                else{
                    edgeM[c-'A'][d-'A']=cost;
                    edgeM[d-'A'][c-'A']=cost;
                }
            }
        }
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                edgeY[i][i]=0;
                edgeM[i][i]=0;
            }
        }
        for(int k=0;k<30;k++){
            for(int i=0;i<30;i++){
                for(int j=0;j<30;j++){
                    edgeM[i][j]=min(edgeM[i][j],edgeM[i][k]+edgeM[k][j]);
                    edgeY[i][j]=min(edgeY[i][j],edgeY[i][k]+edgeY[k][j]);
                }
            }
        }
        cin>>a>>b;
        int ss=a-'A',dd=b-'A';
        int res=inf;
        vector<int>t;
        for(int i=0;i<26;i++){
            if(res>edgeY[ss][i]+edgeM[dd][i]){
                res=edgeY[ss][i]+edgeM[dd][i];
            }
        }
        for(int i=0;i<26;i++){
            if(res==edgeY[ss][i]+edgeM[dd][i]){
                t.push_back(i);
            }
        }
        if(res>=inf){
            cout<<"You will never meet."<<endl;
        }
        else {
            cout<<res<<" ";
            for(int i=0;i<t.size();i++){
                if(i!=t.size()-1)cout<<(char)('A'+t[i])<<" ";
                else cout<<(char)('A'+t[i]);
            }
            cout<<endl;
        }
    }
}
