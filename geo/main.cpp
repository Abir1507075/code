#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);
#define T double
#define lim 10005
class point{
public:
    T x,y;
    point():x(0),y(0){}
    point(T a,T b):x(a),y(b){}
    point operator - (point& q){
        point t;
        t.x=x-q.x;
        t.y=y-q.y;
        return t;
    }
    bool operator < (const point &q)const{
        if(x!=q.x)return x<q.x;
        else return y<q.y;
    }
    bool operator ==(point &q){
        if(x==q.x && y==q.y )return true;
        else return false;
    }
};


T cross (point a,point b){
    return (a.y * b.x)-(a.x * b.y);
}
T orient(point a,point b,point c){
    return cross(b-a,c-a);
}

class segment{
public:
    point a,b;
    segment(){}
    segment(point x,point y):a(x),b(y){}
};


int line(segment s,point t){
    T a=min(s.a.x,s.b.x);
    T b=max(s.a.x,s.b.x);

    T c=min(s.a.y,s.b.y);
    T d=max(s.a.y,s.b.y);

    if(t.x>=a && t.x<=b && t.y>=c && t.y<=d ){
        T aa=s.a.y-s.b.y;
        T bb=s.b.x-s.a.x;
        T cc=s.a.x * s.b.y - s.b.x * s.a.y ;

        if( aa * t.x + bb * t.y + cc != 0) return 0;
        else return 1;
    }
    return 0;
}


int intersect(segment s,segment t){
    T a=orient(s.a,s.b,t.a)*orient(s.a,s.b,t.b);
    T b=orient(t.a,t.b,s.a)*orient(t.a,t.b,s.b);

    if(a<0  and b < 0 ) return 1;
    return 0;
}


point intersection_point(segment a,segment b){
    double a1 = a.a.y - a.b.y;
    double b1 = a.b.x - a.a.x;
    double c1 = a.a.x * a.b.y - a.a.y * a.b.x;

    double a2 = b.a.y - b.b.y;
    double b2 = b.b.x - b.a.x;
    double c2 = b.a.x * b.b.y - b.a.y * b.b.x;


    double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1) ;
    double y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1) ;
    return point(x,y);
}
double areatriangle(point a,point b,point c){
    return  fabs(a.x * (b.y-c.y) - a.y * ( b.x - c.x ) + (b.x * c.y - c.x * b.y));
}

double distance(point a,point b){
    return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)* (a.y-b.y));
}

point start;



class container{
public:
    ll x,y,z,i;
    container(){}
    container(ll a,ll b,ll c,ll d):x(a),y(b),z(c),i(d){}
};

vector<point>common;

void inpoly(segment a,segment arr[],int n,double area){

    double area_a=0,area_b=0;
    for(int i=0;i<n;i++){
        area_a += areatriangle(a.a,arr[i].a,arr[i].b);
        area_b += areatriangle(a.b,arr[i].a,arr[i].b);
    }
    area_a=fabs(area_a)/2;
    area_b=fabs(area_b)/2;
    if(area_a == area_b and area == area_a ){
        common.push_back(a.a);
        common.push_back(a.b);
    }
    else if(area_a == area and area_b!=area ){
        common.push_back(a.a);

    }
    else if(area_a != area and area_b == area){
        common.push_back(a.b);
    }
    for(int i=0;i<n;i++){
            if(intersect(a,arr[i])){
                common.push_back(intersection_point(a,arr[i]));
            }
        }

}


bool cmp(point a,point b){
    ll temp = orient(start,a,b);
    if(temp == 0){
        return distance(start,a)<distance(start,b);
    }
    if(temp>0)return 1;
    else return 0;
}


point h1[105],h2[105];
segment s1[200],s2[200];
point res[200];
int main(){
    int n,m;
    while(1){
        cin>>n;
        if(n==0)break;

        for(int i=0;i<n;i++){
            cin>>h1[i].x>>h1[i].y;
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>h2[i].x>>h2[i].y;
        }
        h1[n]=h1[0];
        h2[m]=h2[0];

        double area_a=0,area_b=0;
        for(int i=1;i<=n;i++){
            area_a += (h1[i-1].x * h1[i].y - h1[i].x * h1[i-1].y);
        }
        for(int i=1;i<=m;i++){
            area_b += (h2[i-1].x * h2[i].y - h2[i].x * h2[i-1].y);
        }
        area_a=fabs(area_a);
        area_b=fabs(area_b);
        area_a/=2;
        area_b/=2;
        for(int i=0;i<n;i++){
            s1[i]=segment(h1[i],h1[i+1]);
        }
        for(int i=0;i<m;i++){
            s2[i]=segment(h2[i],h2[i+1]);
        }
        for(int i=0;i<n;i++){
            inpoly(s1[i],s2,m,area_b);
        }
        for(int i=0;i<m;i++){
            inpoly(s2[i],s1,n,area_a);
        }

        start.x=1000,start.y=1000;
        for(int i=0;i<common.size();i++){
            if(common[i].y<start.y){
                start=common[i];
            }
            else if(common[i].y==start.y){
                if(common[i].x<start.x){
                    start=common[i];
                }
            }
        }
        sort(common.begin(),common.end());
        int st=0;
        for(int i=0;i<common.size();i++){
            while(st>=2 and orient(res[st-2],res[st-1],common[i])<=0){
                st--;
            }
            res[st++]=common[i];
        }
        for(int i=common.size()-2,t=st+1;i>=0;i--){
            while(st>=t and orient(res[st-2],res[st-1],common[i])<=0){
                st--;
            }
            res[st++]=common[i];
        }
        res[st]=res[0];

        double common_area=0;
        for(int i=1;i<=st;i++){
            common_area += ((res[i-1].x * res[i].y ) - (res[i].x * res[i-1].y));
        }
        common_area/=2;
        double res = (area_a + area_b - (2 * fabs(common_area)));
        printf("%8.2f",res);
        common.clear();
    }
    cout<<endl;
}

