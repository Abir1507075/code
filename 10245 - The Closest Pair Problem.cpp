#include<bits/stdc++.h>
using namespace std;


double dis(double x,double y,double a,double b){
    return (x-a)*(x-a)+(y-b)*(y-b);
}




int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        pair<int,int>p[n+10];
        for(int i=0;i<n;i++){
            scanf("%d %d",&p[i].first,&p[i].second);
        }
        double res=1000000000.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
             double d=dis(p[i].first,p[i].second,p[i+1].first,p[i+1].second);
             res=min(res,d);
        }

        if(res>10000){
            printf("INFINITY\n");
        }
        else printf("%.4f\n",res);
    }
}
