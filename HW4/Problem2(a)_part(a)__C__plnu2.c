#include<stdio.h>

int main(){
    int c1, r1, c2,r2,c3,r3,c4,r4;
    int n;

    printf("enter the amount    ");
    scanf("%d",&n);

     c1= n/25;
     r1= n%25;
    printf("No. of quarter denominations %d", c1);
     //printf("\n%d",r1);

     c2= r1/10;
     r2= r1%10;
    printf("\nNo. of Dime denominations %d",c2);
    //printf("\n%d",r2);

    c3= r2/5;
    r3= r2%5;
    printf("\nNo. of Nickel denominations %d",c3);
    //printf("\n%d",r3);

    c4= r3/1;
    r4= r3%1;
    printf("\nNo. of penny denominations %d",c4);
    //printf("\n%d",r4);


}
