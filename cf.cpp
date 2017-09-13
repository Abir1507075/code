#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 1000000
int n;
int a[1005],b[1005];
int c[1000+5]={0},c1[1005]={0};
map<int , int>mp;
int  cal()
{
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==0)temp++;
    }
    return temp;
}
void refresh()
{
    for(int i=1;i<=n;i++)
    {
        if(mp[i]==1000)mp[i]=0;
    }
}
int seek()
{
    for(int i=1;i<=n&&cal();i++)
    {
        if(mp[i]==0)
        {
            mp[i]+=1000;
            return i;
            break;
        }
    }
}
void seek_refresh()
{
    for(int i=1;i<=n&&cal();i++)
    {
        if(mp[i]==0||mp[i]==999)
        {
            mp[i]=0;
        }
    }
}
int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int c[n+5]={0};
    int temp=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i])
        {
            c[i]=a[i];
            c1[i]=a[i];
            mp[a[i]]++;
        }
        else temp++;
    }
    if(temp==1)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
            {
               while(cal())
               {
                    int k=seek();
                    if(k!=a[i]&&k!=b[i])
                    {
                        c[i]=k;
                        mp[k]--;
                        break;
                    }
                }
            }
        }
    }
    if(temp==2)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]!=b[i]&&temp==1)
            {
                while(cal())
               {
                    int k=seek();
                    if(k!=a[i]^k!=b[i])
                    {
                        c[i]=k;
                        mp[k]--;
                        break;
                    }
                }
                refresh();
                temp--;
            }
            else if(a[i]!=b[i]&&temp==2)
            {
                while(cal())
                {
                    int k=seek();
                    if(k!=a[i]^k!=b[i])
                    {
                        c[i]=k;
                        mp[k]--;
                        break;
                    }
                }
                refresh();
            }
        }
    }
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0)flag=true;
    }
    seek_refresh();
    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i]&&temp==1)
            {
                while(cal())
               {
                    int k=seek();
                    if(k!=a[i]^k!=b[i])
                    {
                        c1[i]=k;
                        mp[k]--;
                        break;
                    }
                }
                refresh();
                temp--;
            }
            else if(a[i]!=b[i]&&temp==2)
            {
                while(cal())
                {
                    int k=seek();
                    if(k!=a[i]^k!=b[i])
                    {
                        c1[i]=k;
                        mp[k]--;
                        break;
                    }
                }
                refresh();
            }
        }

    }
    if(flag)
    {
        for(int i=0;i<n;i++)
        {
            cout<<c1[i]<<' ';
        }
    }
    else{
        for(int i=0;i<n;i++)
        {
            cout<<c[i]<<' ';
        }
    }

}
