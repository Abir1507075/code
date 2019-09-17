#include<bits/stdc++.h>
using namespace std;

#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

#define ll long long
#define lim 1005
#define mx 500000000



int bit[lim+10][lim+10];

void update(int x,int y,int val){
    for(int i = x ; i < lim ; i += ( i & ( -i ) ) ){
        for(int j = y ; j < lim ; j+= ( j & ( -j ) ) ){
            bit[i][j]+=val;
        }
    }
}
int query(int x,int y){
    int sum=0;
    for(int i = x ; i > 0 ; i -= ( i & ( -i ) ) ){
        for(int j = y ; j > 0 ; j -= ( j & ( -j ) ) ){
            sum+=bit[i][j];
        }
    }
    return sum;
}
int vis[lim+10][lim+10];


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        int n;
        scanf("%d",&n);
        for(int i=0;i<lim;i++){
            for(int j=0;j<lim;j++){
                bit[i][j]=0;
                vis[i][j]=0;
            }
        }
        printf("Case %d:\n",t);
        for(int i=0;i<n;i++){
            int type,x1,y1;
            scanf("%d %d %d",&type,&x1,&y1);
            x1++,y1++;
            if(type==0){
                if(vis[x1][y1])continue;
                vis[x1][y1]=1;
                update(x1,y1,1);
                //cout<<query(x1,y1)<<endl;;
            }
            else{
                int x2,y2;
                scanf("%d %d",&x2,&y2);
                x2++;y2++;
                int ans=query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1);
                printf("%d\n",ans);
            }
        }
    }
}
