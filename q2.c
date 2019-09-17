#include<stdio.h>


int main(){
    int n;
    printf("Enter Value of N: ");
    scanf("%d",&n);
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            printf("1 ");
        }
        for(int j=n/2;j<n;j++){
            printf("0 ");
        }
        printf("\n");
    }
    for(int i=n/2;i<n;i++){
        for(int j=0;j<n;j++){
            printf("1 ");
        }
        printf("\n");
    }

}
