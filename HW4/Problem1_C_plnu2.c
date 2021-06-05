#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
    int i=0,j=0;
    int l=5;
    int n=4;
    int val[]={3,4,5,6};
    int w[]={2,3,4,5};


    int knap[n+1][l+1];

    for(i=0;i<n+1;i++){
        knap[i][0]=0;
    }

    for(j=0;j<l+1;j++){
        knap[0][j]=0;
    }


    //This is the main algorithm
    for(j=1;j<l+1;j++){
        for(i=1;i<n+1;i++){
            if(w[i-1]>j){
                knap[i][j]= knap[i-1][j];
            }
            else{
                knap[i][j]= fmax(knap[i-1][j-(w[i-1])]+val[i-1],knap[i-1][j]);
                if (knap[i-1][j-(w[i-1])]+val[i-1]> knap[i-1][j]){
                    printf("\nItem %d is in knapsack\n",i );
                }

            }

        }
    }

    printf("\nThe max value of the knapsack is: ");
    printf("%d",knap[n][l]);

   // printf("Item %d is in knapsack ", );

    //for(j=1;j<l+1;j++){
      //  for(i=1;i<n+1;i++){
        //        printf("%d",knap[i][j]);


        //}
    //}


return 0;


}
