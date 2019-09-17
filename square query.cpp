#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 1000

int n,m;
int arr[lim+10][lim+10];
int tree[1000005];




void init(int pos,int a,int b,int c,int d){
    if(a>c||b>d)return;
    if(a==c&&b==d){
        tree[pos]=arr[a][b];
        return ;
    }
    int x=(a+c)/2;
    int y=(b+d)/2;
    init(4*pos+1,a,b,x,y);
    init(4*pos+2,x+1,b,c,y);
    init(4*pos+3,a,y+1,x,d);
    init(4*pos+4,x+1,y+1,c,d);
    tree[pos]=max(max(tree[4*pos+1],tree[4*pos+2]),max(tree[4*pos+3],tree[4*pos+4]));
    //cout<<tree[pos]<<endl;
}

int query(int pos,int a,int b,int c,int d,int a1,int b1,int c1,int d1){
    if(a>c||b>d)return 0 ;
    if(a>c1||c<a1||b>d1||d<b1)return 0;
    if((a>=a1&&b>=b1)&&(c<=c1&&d<=d1)){
        return tree[pos];
    }
    int x=(a+c)/2;
    int y=(b+d)/2;
    int t1=query(4*pos+1,a,b,x,y,a1,b1,c1,d1);
    int t2=query(4*pos+2,x+1,b,c,y,a1,b1,c1,d1);
    int t3=query(4*pos+3,a,y+1,x,d,a1,b1,c1,d1);
    int t4=query(4*pos+4,x+1,y+1,c,d,a1,b1,c1,d1);
    return max(max(t1,t2),max(t3,t4));
}



int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        init(0,0,0,n-1,n-1);
        //cout<<tree[0]<<endl;
        printf("Case %d:\n",t);
        for(int i=0;i<m;i++){
            int a,b,s;
            scanf("%d %d %d",&a,&b,&s);
            a--,b--;
            int c=a+s-1;
            int d=b+s-1;
            int res=query(0,0,0,n-1,n-1,a,b,c,d);
            printf("%d\n",res);
        }
        for(int i=0;i<=1000000;i++){
            tree[i]=0;
        }
    }
}
