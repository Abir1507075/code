#include<stdio.h>
#include<math.h>


int main(){
    int a,b,c;
    printf("Enter Value For a b c :");
    scanf("%d %d %d",&a,&b,&c);
    int img= b*b -4*a*c;
    if(img<0){
        printf("IMAGINARY\n");
    }
    else{
        float root1=( (float)-b + sqrt(img) ) /(2.0*a);
        float root2=( (float)-b - sqrt(img) ) /(2.0*a);
        printf("Root1 = %f \nRoot2 = %f \n",root1,root2);
    }

}
