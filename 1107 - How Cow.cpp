#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        int q;
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if((a>=x1&&a<=x2)&&(b>=y1&&b<=y2))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }


        }
    }
}
