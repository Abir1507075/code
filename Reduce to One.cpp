#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define md 1000000007

ll ans[1000006];

void cal(){
    ans[1]=1;
    for(int i=2;i<=1000000;i++){
        ans[i]=i%md + ans[i-1] % md +( i %md * ans[i-1] % md )%md;
        ans[i]%=md;
    }
}


int main(){
    int t;
    cin>>t;
    cal();
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
}
