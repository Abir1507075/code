//1083 - Histogram
//
//

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


//1082 - Array Queries
//
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000000
 
 
void tree(int n[],int result[],int node,int lo,int hi)
{
    if(lo==hi)
    {
        result[node]=n[lo];
        return;
    }
    int mid=(lo+hi)/2;
    int left=node*2;
    int right=(node*2)+1;
    tree(n,result,right,mid+1,hi);
    tree(n,result,left,lo,mid);
    result[node]= result[left]<=result[right] ? result[left]:result[right];
}
int query(int n[],int result[],int node,int lo,int hi,int i,int j)
{
    if(i<=lo&&j>=hi)return result[node];
 
    if(i>hi||j<lo) return mx;
    int mid=(hi+lo)/2;
    int right= node*2 +1;
    int left=node*2;
    int p1=query(n,result,left,lo,mid,i,j);
    int p2=query(n,result,right,mid+1,hi,i,j);
 
    return p1<=p2? p1: p2;
 
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        int a,q;
        scanf("%d %d",&a,&q);
        int n[a+5];
        int result[a*3];
        for(int i=1;i<=a;i++)
        {
            scanf("%d",&n[i]);
        }
        tree(n,result,1,1,a);
        printf("Case %d:\n",t);
        for(int i=0;i<q;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",query(n,result,1,1,a,x,y));
 
        }
    }
}

