#include<bits/stdc++.h>
using namespace std;
int main()
{
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        int a[n+10];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int k=0;
        for(int i=0;i<q;i++)
        {
            char c;
            int x,y;
            getchar();
            scanf("%c",&c);


            if(c=='R')
            {
                for(int j=0;j<n/2;j++)
                {
                    int temp=a[j];
                    a[j]=a[n-j-1];
                    a[n-j-1]=temp;
                }
            }
            else if(c=='S')
            {
                scanf("%d",&x);
                for(int i=0;i<n/2;i++)
                {
                    a[i]+=x;
                    a[n-i-1]+=x;
                }
                if(n%2==1)a[n/2]+=x;
            }
            else if(c=='P')
            {
                scanf("%d %d",&x,&y);

                int temp=a[x];
                a[x]=a[y];
                a[y]=temp;
            }
            else if(c=='M')
            {
                scanf("%d",&x);
                for(int i=0;i<n/2;i++)
                {
                    a[i]*=x;
                    a[n-i-1]*=x;
                }
                if(n%2==1)a[n/2]*=x;
            }
            else
            {
                scanf("%d",&x);
                for(int i=0;i<n/2;i++)
                {
                    if(a[i]!=0)
                        a[i]/=x;
                    if(a[n-i-1]!=0)
                        a[n-i-1]/=x;
                }
                if(n%2==1)a[n/2]/=x;
            }

        }
        printf("Case %d:\n",t);
        for(int i=0;i<n-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n-1]);



    }
}
