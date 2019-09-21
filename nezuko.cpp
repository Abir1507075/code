#include<bits/stdc++.h>
using namespace std;
#define pi atan(1)*4;
typedef long long ll;
bool ch[1000010];
vector<ll> dv[1000010];
void gen(){
    for(int i = 2; i <= 1000000; i += 2)
        dv[i].push_back(2);
    for(int i = 3; i * i <= 1000000; i += 2){
        if(!ch[i]){
            for(int j = i * i; j <= 1000000; j += 2 * i)
                ch[j] = true;
        }
    }
    for(int i = 3; i <= 1000000; i += 2){
        if(!ch[i]){
            //cout << i <<  " ";
//            if(i == 3167)
//                cout << i << endl;
            for(int j = 2 * i; j <= 1000000; j += i){
                dv[j].push_back(i);
//                if(i == 3167)
//                    cout << j << " ";
            }
        }
//        if(i == 3167) cout << endl;
    }
}

int main(){

    gen();
//    for(int i=3;i<10000;i+=2){
//        if(!ch[i])cout<<i<<endl;
//    }
    ll t, n, sum;
    scanf("%lld", &t);
    while(t--)
    {
        sum = 0;
        scanf("%lld", &n);
        int sz = dv[n].size();
//        for(int i = 0; i < sz; i++)
//            cout << dv[n][i] << " ";
//        cout << endl;
        sz = 1 << sz;
        for(int i = 1; i < sz; i++){
            int t = i, k = 0, kk = 0;
            ll a = 1;
            while(t != 0){
                if(t % 2){

                    a *= dv[n][k], kk++;
//                    cout << " dv " << dv[n][k];
                }
                t /= 2;
                k++;
            }
//            cout << endl;
//            cout << a << endl;
            ll g = (n - 1) / a;
            if(kk&1)
                sum += (g * (g + 1) / 2) * a;
            else
                sum -= (g * (g + 1) / 2) * a;
        }
        printf("%lld\n", sum);
    }

}

