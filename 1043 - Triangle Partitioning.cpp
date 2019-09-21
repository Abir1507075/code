#include<bits/stdc++.h>
using namespace std;


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        double a,b,c,r;
        scanf("%lf %lf %lf %lf",&a,&b,&c,&r);
        double res = sqrt(r/(r+1))*a;
        printf("Case %d: %.9f\n",t,res);
    }
}
