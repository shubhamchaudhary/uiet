/**
 *       Name:        Shubham Chaudhary
 *       Roll No:     UE113090
 *       Branch:      CSE Sec.2
 *       Lab:         Analysis and Design of Algorithm
 *       Program:     Assembly Line Scheduling - Find fastest way out of factory
 **/
#include <stdio.h>
//Global Constants
//const int rMax=20,cMax=20;
#define rMax 20
#define cMax 20

    /*
    int
        r[rMax]={0},
        c[cMax]={0},
        m[rMax][cMax] = { 0 },
        p[rMax+1]={0},
        s[rMax][cMax]={0};
    int
        r[rMax],
        c[cMax],
        m[rMax][cMax],
        p[rMax+1],
        s[rMax][cMax];
    */
    int n;
    int i,j,k,l,q;
    int r[rMax]={0};
    int c[cMax]={0};
    int p[rMax+1]={0};
    int s[rMax][cMax];
    int m[rMax][cMax];

//void printPran(int *m,int* s,int i , int j);
void printPran(int i , int j);
int main(){

    //Input
    /*
    for(i=0; i<rMax; i++)
      memset(r[i],0,sizeof(int));
    for(j=0; j<cMax; j++)
        memset(c[j],0,sizeof(int));
    for(i=0; i<rMax; i++)
      memset(p[i],0,sizeof(int));
    
    for(i=0; i<rMax; i++){
      for(j=0; j<cMax; j++)
        memset(s[i][j],0,sizeof(int));
     }
    for(i=0; i<rMax; i++){
      for(j=0; j<cMax; j++)
        memset(m[i][j],0,sizeof(int));
     }
     */
    for(i=0; i<rMax; i++){
      for(j=0; j<cMax; j++)
        s[i][j]=0;
     }
    for(i=0; i<rMax; i++){
      for(j=0; j<cMax; j++)
            m[i][j]=0;
     }
    printf("\nEnter no of matrices: ");
    scanf("%d",&n);
    for(i=0;i<=n+1;i++){
        printf("Enter p[%d]: ",i);
        scanf("%d",&p[i]);
    }
    /*
    for(i=0;i<n;i++){
        printf("Enter r[%d]: ",i);
        scanf("%d",&r[i]);
        printf("Enter c[%d]: ",i);
        scanf("%d",&c[i]);
    }
    */    
    //end Input

    //Algorithm
    for(i=0;i<n;i++){
        m[i][i]=0;
    }
    for(l=1;l<n;l++){
        for(i=0;i<n-l+1;i++){
            j=i+j-1;
            m[i][j]=1000;
            for(k=i;k<=j-1;k++){
                q=m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
    //end algo
    printf("\nmatrix m\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\nmatrix s\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    //printPran(0,n);
    return 0;
}
void printPran(int i , int j){
    if(i==j){
        printf("A[%d]",i);
    }
    else{
        printf(" ( ");
        printPran(i,s[i][j]);
        printPran(s[i][j]+1,j);
        printf(" ) ");
    }
}
