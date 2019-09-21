#include<bits/stdc++.h>
using namespace std;

int main()
{
    double h, m, ch, cm;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf %lf %lf", &h, &m, &ch, &cm);
        for(double x = 0; x <= 360; x += (360.0 / (h * m))){
            int X = round(h * x);
            if(X % 360 == round(x)){
                double mn = m*h*x / 360;
                int tm = cm + round(mn);
                int hm = tm / int(m);
                printf("%dh %dm\n", (int(ch) + hm) % int(h), tm % int(m));
            }
        }

    }

    return 0;
}
