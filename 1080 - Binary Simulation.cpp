#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int one,zero,prop;
    node():one(0),zero(0),prop(0){}
    node(int a,int b,int c):one(a),zero(b),prop(c){}
};
string s;
node tree[3*100005];

void build(int pos,int lo,int hi)
{
    if(lo==hi)
    {
        if(s[lo]=='1')tree[pos]=node(1,0,0);

        else if(s[lo]=='0')tree[pos]=node(0,1,0);

        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    build(left,lo,mid);
    build(right,mid+1,hi);
    tree[pos].prop=0;
}

void update(int pos,int lo,int hi,int x,int y)
{
    if(lo>y||hi<x)return;
    if(lo>=x&&hi<=y)
    {
        tree[pos].prop++;
        return;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    update(left,lo,mid,x,y);
    update(right,mid+1,hi,x,y);
}


int query(int pos,int lo,int hi,int x,int c=0)
{
    if(lo>x||hi<x)return 0;
    if(lo==x&&hi==x)
    {
        return tree[pos].prop+c;
    }
    int left=pos*2+1;
    int right=pos*2+2;
    int mid=(hi+lo)/2;
    int p1=query(left,lo,mid,x,tree[pos].prop+c);
    int p2=query(right,mid+1,hi,x,tree[pos].prop+c);
    return p1+p2;
}

int main()
{
//freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    int tst;
    scanf("%d",&tst);
    for(int t=1;t<=tst;t++)
    {
        cin>>s;

        build(0,0,s.size()-1);
        int q;
        scanf("%d",&q);


        printf("Case %d:\n",t);
        for(int i=0;i<q;i++)
        {
            char p;
            int a,b;
            getchar();
            scanf("%c",&p);
            getchar();
            if(p=='I')
            {
                scanf("%d %d",&a,&b);
                update(0,0,s.size()-1,a-1,b-1);
            }
            else
            {
                scanf("%d",&a);
                int k=query(0,0,s.size()-1,a-1);

                if(k%2==0)
                {
                    printf("%c\n",s[a-1]);
                }
                else
                {
                    if(s[a-1]=='1')printf("0\n");

                    else printf("1\n");
                }
            }

        }

    }
}
