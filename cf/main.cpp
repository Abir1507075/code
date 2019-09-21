#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 400005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define md 998244353
#define pi acos(-1)
#define e .0000001


int main(){
    int tst,t=0;
    scanf("%d",&tst);
    while(tst--){
        t++;
        double r,n;
        scanf("%lf %lf",&r,&n);
        double lo=0.0,hi=r,res=0;
        while(lo+e<hi){
            double mid = (lo+hi)/2;
            double f = n*atan(mid/(r-mid));

            double err=fabs(pi-f);
            cout<<lo<<" "<<hi<<endl;
            if(err<=e){
                res=mid;
                break;
            }
            else if(f>pi){
                hi=mid;
            }
            else lo=mid;
        }
        cout<<res<<endl;
    }
}
