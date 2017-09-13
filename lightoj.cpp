#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int n;
        scanf("%d",&n);
        int a[n+5];
        a[0]=-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        a[n+1]=-1;
        stack<int> s,s1;
        s.push(0);
        s1.push(n+1);
        vector<int>left,right;
        right.push_back(0);
 
        left.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(a[s.top()]<a[i])
            {
                left.push_back(s.top());
                s.push(i);
            }
            else
            {
                while(!s.empty()&&a[s.top()]>=a[i])
                {
                    s.pop();
                }
                left.push_back(s.top());
                s.push(i);
            }
        }
 
        for(int i=n;i>0;i--)
        {
            if(a[s1.top()]<a[i])
            {
                right.push_back(s1.top());
                s1.push(i);
            }
            else
            {
                while(!s1.empty()&&a[s1.top()]>=a[i])
                {
                    s1.pop();
 
                }
                right.push_back(s1.top());
                s1.push(i);
            }
        }
        ll k,temp=0;;
        for(int i=1;i<right.size();i++)
        {
            k=(right[right.size()-i]-left[i]-1)*a[i];
 
            if(k>=temp)temp=k;
 
        }
        printf("Case %d: %lld\n",t,temp);
 
 
    }
}
