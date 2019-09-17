#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int q;
    cin>>q;
    while(q--){
        ll k,n,a,b;
        cin>>k>>n>>a>>b;
        ll lo=0,hi=n;
        ll ans=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            ll justplay = mid * a ;
            ll chargeplay = (n-mid) * b ;

            ll tot=justplay + chargeplay ;

            ll rem = tot - k;
            if( rem >= 0 ){
                hi=mid-1;
            }
            else{
                lo=mid+1;
                ans=mid;
            }
        }
        cout<<ans<<endl;
    }
}
