#include<stdio.h>
#include<math.h>


int main(){
    int coins[]={1,5,6,8};
    int c=4,i=0,j=0;
    int n=11;
    int map[c][n+1];

    //for(i=0;i<c;c++){
      //  for(j=0;j<=n;j++){
        //    map[0][j]=0;
        //}
    //}

    for(i=0;i<c;c++){
        for(j=0;j<=n;j++){
            map[i][0]=0;
        }
    }


    for(j=0;j<=n;j++){
            map[0][j]=j;
        }


     for(i=1;i<c;c++){
        for(j=0;j<n+1;j++){
            if (j>= coins[i]){
                map[i][j]= fmin(map[i-1][j],1+map[i][j-coins[i]]);
            }
            else{
                map[i][j]= map[i-1][j];

            }
        }
    }

    //for(j=0;j<n+1;j++){
      //  printf(" %d",map[1][j]);
    //}


    printf("\nNo. of coins needed are: ");
    printf("%d",map[c][n]);


    return 0;
}
