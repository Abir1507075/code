#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi atan(1)*4
int main(){
    vector< pair<double,double> >halfcircle;
    for(int i=0;i<=360;i++){
        double x = 3 * cos( i* pi /180 ) ;
        double y = 3 * sin( i* pi /180 ) ;
        if(y >= 0.0){
            halfcircle.push_back(make_pair(x,y));
        }
    }
    sort(halfcircle.begin(),halfcircle.end());
    //reverse(halfcircle.begin(),halfcircle.end());
    for(int i=0;i<halfcircle.size();i++){
        //body.push_back(halfcircle[i]);
        cout<<halfcircle[i].first<<" "<<halfcircle[i].second<<endl;
    }
}
