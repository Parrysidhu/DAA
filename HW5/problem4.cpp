#include<iostream>
#include<string.h>
#include<algorithm>

using namespace std;

 void LCS(char *A, char *B,int a,int b){
    int i,j;
    int c[a+1][b+1];


    for(i=0;i<a;i++){
            c[i][0]=0;  //case1 i=0
        }


    for(j=0;j<b;j++){   //case1 j=0

            c[0][j]=0;

    }

    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            if(A[i-1]==B[j-1]){
                c[i][j]=c[i-1][j-1]+1;   //case2 i.e. x[i]==y[j]
                cout<<"value included in LCS is"<< B[j-1]<<endl;
            }
            else
                c[i][j]=std::max(c[i-1][j],c[i][j-1]); //case3 i.e. x[i]!=y[j]
        }
    }



    cout<< "Max LCS length is:"<<c[a+1][b+1]<<endl;


 }


 int main(){
    char A[]="BDCB";
    char B[]="BACDB";

    int a=strlen(A);
    int b= strlen(B);
    cout<<a<<endl;
    cout<<b<<endl;

    LCS(A,B,a,b);

    return 0;
 }

