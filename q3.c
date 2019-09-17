#include<stdio.h>

int main(){
    int n;
    printf("Enter value for N:");
    scanf("%d",&n);
    if(n>=1){
        printf("1 ");
    }
    if(n>=2){
        printf("1 ");
    }
    int a=1,b=1,c;
    while(a+b<=n){
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
    }

}
