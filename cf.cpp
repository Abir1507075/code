//814B - An express train to reveries
//
//

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


//solution 727B - Bill Total Value
//
//
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool number(char c)
{
    if((c>='0'&&c<='9')||c=='.')return true;
    else return false;
}

bool cha(char c)
{
    if(c>='a'&&c<='z')return true;
    else return false;
}

double make_number(char c)
{
    return (c-48);
}
int main()
{
    string s;
    cin>>s;
    string num="";
    double ans=0;
    int frac=0;
    for(int i=0;i<s.size();i++)
    {
        while(cha(s[i])&&i<s.size())
        {
            i++;
        }
        while(number(s[i])&&i<s.size())
        {
            num=num+s[i];
            i++;
        }
        int mod=1; double temp=0;
        int point=0;
        if(num[num.size()-3]=='.')
        {
           // temp= make_number(num[num.size()-1])/100+ make_number(num[num.size()-2])/10;

            point = make_number(num[num.size()-1])+ make_number(num[num.size()-2])*10;
            for(int j=num.size()-4;j>=0;j--)
            {
                     if(num[j]=='.')continue;
                {

                    double n=make_number(num[j]);
                    temp=temp+n*mod;
                    mod=mod*10;
                }
            }
        }
        else
        {
            for(int j=num.size()-1;j>=0;j--)
            {
                 if(num[j]=='.')continue;
                    double n=make_number(num[j]);
                    temp=temp+n*mod;
                    mod=mod*10;
            }
        }
        //cout<<"temp "<<temp<<endl;
        ans=ans+temp;
        frac=frac+point;
        num="";
    }
    //printf("%.2lf\n",ans);
    //cout<<frac<<endl;
    int difect;
    int hold=0;
    hold=frac%100;
    frac=frac/100;
    //cout<<frac<<endl;
    //cout<<ans<<endl;
    int test=ans;
    test=test+frac;
    //cout<<test<<endl;
    {
        int temp=test;
        int cnt=0;
        vector<char>v;
        while(temp)
        {
            if(cnt==3)
            {
                v.push_back('.');
                cnt=0;
            }
            int p=temp%10;
            char l=p+48;
            v.push_back(l);
            temp=temp/10;
            cnt++;
        }
        if(v.size()==0)cout<<'0';
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i];
        }
        if(hold==0&&frac==0)return 0;
        if(hold)printf(".%02d\n",hold);
        else if(test==ans&&!hold)printf(".%02d\n",frac);
    }


}
//474B - Worms
//
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[1000005];
int bi_search(int hi,int lo,int n)
{
    while(lo<=hi)
    {
        int mid=(hi+lo)/2;
        if(mid==n)return a[mid];
        else if(mid>n)
        {
            hi=mid-1;
        }
        else if(mid<n)
        {
            lo=mid+1;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    int b=1;
    for(int i=1;i<=n;i++)
    {
        int q;
        cin>>q;
        for(int j=0;j<q;j++,b++)
        {
            a[b]=i;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        cout<<bi_search(b,1,q)<<endl;
    }


}
