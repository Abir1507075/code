#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.00);

int main()
{
    double n ,r;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lf %lf", &n, &r);
        if(n == 1) printf("%0.4lf\n", 4 * r);
        else if(n == 2 || (int(n) & 1)){
            //cout << sin(2 * pi / (n + 1)) << " " << sin((pi / 2)* ((n-1) / (n+1))) << endl;
            double ans = r * (sin(2 * pi / (n + 1)) / sin((pi / 2)* ((n-1) / (n+1))));
            printf("%0.4lf\n", (n + 1) * ans);
        }
        else{
            double ans = r * sin(pi / (n + 1)) / sin((pi / 2) / (n + 1));
            printf("%0.4lf\n", (n + 1) * ans);
        }
    }

    return 0;
}
