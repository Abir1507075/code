#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        char s[100];
        scanf("%s",s);
        int l=strlen(s);
        bool flag =false;
        for(int i=0;i<l/2;i++)
        {
            if(s[i]!=s[l-i-1])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            printf("Case %d: No\n",t);
        }
        else printf("Case %d: Yes\n",t);
}
}
