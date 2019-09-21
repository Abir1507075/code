#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{

    ll sum = 0;
    ll n = 1000000;
    while(cin >> n){
            sum = 0;
    for(ll i = 0; i < n; i++)
        if(__gcd(n, i) > 1)
            cout << i << " " , sum += i;
    cout << sum << endl;
    }
}
