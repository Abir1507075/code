#include<bits/stdc++.h>
#define ll long long
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);


using namespace std;

ll arr[100];



void pre(){
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=100;i++){
        arr[i] = ( arr[i-1] + arr[i-2] ) % 10;
       // cout<<arr[i]<<" "<<i<<endl;
    }
}


int main(){
    //fin;
    //fout;

    pre();
    int tst;
    cin>>tst;
    while(tst--){
        ll n;
        cin>>n;
        n--;
        n = n % 60 ;
        if(n==0){
            cout<<"0"<<endl;
            continue;
        }
        if( n%2 == 0){
            cout<<arr[n-1]<<endl;
        }
        else cout<<arr[n]<<endl;

    }
}
