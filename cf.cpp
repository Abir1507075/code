#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lim 200000
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

vector<int>edge[lim+10];

ll track[lim];

vector<pair<ll,ll> >notsorted,sorted;
int main(){
    ll n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        ll t,l,r;
        cin>>t>>l>>r;
        if(t==1){
            sorted.push_back(make_pair(l,r));
        }
        else{
            notsorted.push_back(make_pair(l,r));
        }
    }
    sort(sorted.begin(),sorted.end());
    sort(notsorted.begin(),notsorted.end());
    for(int i=0;i<sorted.size();i++){
        for(int j=i+1;j<sorted.size();j++){
            if(sorted[i].second >= sorted[j].first ){
                sorted[i].second = sorted[j].second;
                sorted.erase(sorted.begin()+j);
            }
        }
    }
    bool flag=true;
    for(int i=0;i<notsorted.size();i++){
        for(int j=0;j<sorted.size();j++){
            if(notsorted[i].first >= sorted[j].first and notsorted[i].second<= sorted[i].second){
                flag=false;
                break;
            }
            else{
                if(notsorted[i].first>sorted[j].second or notsorted[i].second< sorted[j].first){

                }
                else if(notsorted[i].second > sorted[j].second and notsorted[i].first < sorted[j].second){
                    notsorted[i].first=sorted[j].second;
                }
                else{
                    notsorted[i].second=sorted[j].first;
                }
            }
        }
        if(!flag)break;
    }
    if(!flag){
        cout<<"NO"<<endl;
    }

    else{
        for(int i=0;i<notsorted.size();i++){

        }
        sort(sorted.begin(),sorted.end());
        int arr[lim]={0};
        ll cnt=10000000000;
        for(int i=0;i<sorted.size();i++){
            for(int j=sorted[i].first;j<=sorted[i].second;j++){
                arr[j]=cnt;
            }
            cnt+=100000;
        }
    }

}
