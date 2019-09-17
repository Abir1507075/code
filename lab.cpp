#include<bits/stdc++.h>
using namespace std;

int chrom[4][6];
//srand (time(NULL));
int best=-99999;
int best_i[6];
void init()
{

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<6;j++)
        {

            chrom[i][j]=rand()%2;

        }


    }




}
int btoi(int i)
{    int k=1,t=0;

        for(int j=5;j>0;j--)
        {

            t+=chrom[i][j]*k;
            k*=2;

        }

   if(chrom[i][0]==1)
      t*=-1;



    return t;

}
int evaluation(int i)
{
int a=btoi(i);

int t= -a*a+5;
if(t>best)
{

    best=t;
    for(int j=0;j<6;j++)
        best_i[j]=chrom[i][j];
}
return t;



}
void print_seq()
{

    for(int i=0;i<4;i++)
    {   cout<<"sequence "<<i<<" :";
        for(int j=0;j<6;j++)
        {

            cout<<chrom[i][j]<<" ";

        }

        cout<<btoi(i);
        cout<<endl;

    }





}
vector< pair <int,int> >v;

void selection()
{
    v.clear();

for(int i=0;i<4;i++)
    {
        int l=evaluation(i);
        v.push_back(make_pair(l,i));

    }

sort(v.begin(),v.end());



for(int i=0;i<2;i++)
{

    for(int j=0;j<6;j++)
    {
        chrom[v[i].second][j]=chrom[v[i+2].second][j];

    }

}


}



void crossover()
{

    int r=rand()%6;

    for(int i=r;i<6;i++)
    {

      int t1;
      t1=chrom[0][i];
      chrom[0][i]=chrom[1][i];
      chrom[1][i]=t1;

    }


}
void mutation()
{
	int i=rand()%50;
	if(i==20)
	{
		int a=rand()%4;
		int k=rand()%6;

		chrom[a][k]=1-chrom[a][k];

	}
}




int main(){

init();

print_seq();

cout<<endl;

for(int i=0;i<500;i++){
cout<<"iteration no:"<<i<<endl;
cout<<endl<<"After selection :"<<endl;
selection();
print_seq();

cout<<endl<<"After crossover :"<<endl;
crossover();
print_seq();

cout<<endl<<"After mutation with 2% probability :"<<endl;
mutation();
print_seq();
cout<<"best result: "<<best<<"     "<<"best sequence: ";
 for(int j=0;j<6;j++)
        cout<<best_i[j]<<" ";
cout<<endl<<endl<<endl<<endl;

}

}

