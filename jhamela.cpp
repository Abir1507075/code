#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 300005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define md 998244353


ll factor[lim+10];

void init(){

    factor[0]=1;
    for(int i=1;i<=lim;i++){
        factor[i] = ( (factor[i-1] % md) * (i % md) ) % md;
    }

}


int main(){

    init();

    ll n;
    cin>>n;

    pair<ll,ll>arr[n+10],temp[n+10];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        temp[i]=arr[i];
    }
    sort(arr,arr+n);
    sort(temp,temp+n,[](pair<ll,ll>a,pair<ll,ll>b)
         {
             if(a.second!=b.second)return a.second<b.second;
             else return a.first<b.first;
         });

    ll f1=1,f2=1,tot=1;
    for(int i=1;i<n;i++){
        if(arr[i].first== arr[i-1].first){
            tot++;
        }
        else{
            f1 = ( f1 % md * factor[tot] % md ) % md;
            tot=1;
        }
    }
    f1 = ( f1 % md * factor[tot] % md ) % md;
    tot=1;
    for(int i=1;i<n;i++){
        if(temp[i].second== temp[i-1].second){
            tot++;
        }
        else{
            f2 = ( f2 % md * factor[tot] % md ) % md;
            tot=1;
        }
    }
    f2 = ( f2 % md * factor[tot] % md ) % md;

    tot=1;
    ll com = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==temp[i]){
            if(arr[i]==arr[i-1] and temp[i]==temp[i-1]){
                tot++;
            }
            else{
                com = (com % md * factor[tot] % md) % md;
                tot=1;
            }
        }
        else{
            break;
        }
    }
    com = ((com % md) * ( factor[tot] % md )) % md;
    cout<<com<<endl;
    ll ans = (((factor[n] % md) - ((f1+f2)%md) + (com % md) ) + md) % md;
    cout<<ans<<endl;
}


