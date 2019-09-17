#include<bits/stdc++.h>
using namespace std;
#define ll long long


class point{
public:
    ll x,y;
    point(){}
    point(ll a,ll b):x(a),y(b){}
    point operator -(point& q){
        point t;
        t.x=x-q.x;
        t.y=y-q.y;
        return t;
    }
    point operator +(point& q){
        point t;
        t.x=x+q.x;
        t.y=y+q.y;
        return t;
    }
    bool operator <(point& q){
        if(x!=q.x )return x<q.x;
        else return y<q.y;
    }
};
point start;
ll cross(point a,point b){
    return (a.x*b.y - a.y*b.x);
}

ll orient(point a,point b,point c){
    return cross(b-a,c-a);
}

point arr[100005];

class segment{
public:
    int x1,y1,x2,y2;
    segment(){}
    segment(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){}

};

segment seg[100005];


bool insegment(int i,point t){
    int a=min(seg[i].x1,seg[i].x2);
    int b=max(seg[i].x1,seg[i].x2);

    int c=min(seg[i].y1,seg[i].y2);
    int d=max(seg[i].y1,seg[i].y2);

    if( a <= t.x && b>=t.x && c <= t.y && d>= t.y){
        return true;
    }
    return false;
}


bool inrange(int i,int j){
    ll a=orient(point(seg[i].x1,seg[i].y1),point(seg[i].x2,seg[i].y2),point(seg[j].x1,seg[j].y1));
    ll b=orient(point(seg[i].x1,seg[i].y1),point(seg[i].x2,seg[i].y2),point(seg[j].x2,seg[j].y2));

    ll c=orient(point(seg[j].x1,seg[j].y1),point(seg[j].x2,seg[j].y2),point(seg[i].x1,seg[i].y1));
    ll d=orient(point(seg[j].x1,seg[j].y1),point(seg[j].x2,seg[j].y2),point(seg[i].x2,seg[i].y2));

    ll e=orient(point(seg[i].x2,seg[i].y2),point(seg[i].x1,seg[i].y1),point(seg[j].x1,seg[j].y1));
    ll f=orient(point(seg[i].x2,seg[i].y2),point(seg[i].x1,seg[i].y1),point(seg[j].x2,seg[j].y2));

    ll g=orient(point(seg[j].x2,seg[j].y2),point(seg[j].x1,seg[j].y1),point(seg[i].x1,seg[i].y1));
    ll h=orient(point(seg[j].x2,seg[j].y2),point(seg[j].x1,seg[j].y1),point(seg[i].x2,seg[i].y2));
    if( ( a * b <= 0 ) && ( c * d <= 0 ) && (e * f <= 0 ) &&( g * h <= 0) )return true;
    return false;
}


bool valid(int i,int j){
    ll a=insegment(i,point(seg[j].x1,seg[j].y1));
    ll b=insegment(i,point(seg[j].x2,seg[j].y2));
    ll c=insegment(j,point(seg[i].x1,seg[i].y1));
    ll d=insegment(j,point(seg[i].x2,seg[i].y2));
    if(a||b||c||d)return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector< pair<int,int> >dhal;
        for(int i=0;i<n;i++){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            seg[i]=segment(a,b,c,d);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int temp=0;
            int a1=seg[i].y1-seg[i].y2;
            int b1=seg[i].x2-seg[i].x1;
            int c1= seg[i].x1 * seg[i].y2 - seg[i].x2 * seg[i].y1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int a2=seg[j].y1-seg[j].y2;
                int b2=seg[j].x2-seg[j].x1;
                int c2= seg[j].x1 * seg[j].y2 - seg[j].x2 * seg[j].y1;

                if(a1==a2 && b1==b2 && c1==c2) {
                    if(valid(i,j)){
                        temp++;
                        break;
                    }
                    else continue;
                }

                if(a1==a2 && b1==b2 ) continue;
                if(inrange(i,j)){
                    temp++;
                    break;
                }
             }
             if(temp==0)cnt++;
        }
        cout<<cnt<<endl;
    }
}
