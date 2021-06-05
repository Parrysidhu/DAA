#include<stdio.h>
#include<math.h>

int main(){

    int c=0,k=0,n=0,d=0,r=0;
    int i=0;
    int arr[k+1];

    printf("enter value for c\n");
    scanf("%d",&c);
    printf("\nenter value for k\n");
    scanf("%d",&k);
    for(i=0;i<=k;i++){
        arr[i]= pow(c,i);

    }

    for(i=0;i<=k;i++){
        printf(" %d",arr[i]);
    }

    printf("\nenter the value to find denominations of:  ");
    scanf("%d",&n);


    for(i=k;i>=0;i--){
        d= n/arr[i];
        printf("\nNo. of denominations of %d are %d\n",arr[i],d);
        r= n%arr[i];
        n=r;
    }


    return 0;

}
