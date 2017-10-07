#include<bits/stdc++.h>
using namespace std;
double  cal(double a,double b,double c,double d)
{

    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int a,b,c,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        double r=cal(a,b,c,d);
        double x=cal(c,d,e,f);
        double angle=(x/r)*(x/r);
        angle=acos(1-angle*.5);
        printf("Case %d: %.8lf\n",t,angle*r);

    }
}
