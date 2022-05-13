#include <stdio.h>
#include "algo.h"
/**
    X = what algo
    Y = how many processes
    Z = for round robin, the steps chuchu
    
    A = proccess ID
    B = arrival time
    C = burst time
**/

int main(void) {
    char file[20];
    int X, Y, Z;
    int A[100], B[100], C[100]; //Y CAN BA BE 3-100 ACCORDING TO SPECS SO ABC MAY BE UP TO 100
    int i;
    
    printf("Enter file name: ");
    scanf("%s", file);
    
    FILE* ptr = fopen(file, "r");
    if (ptr == NULL) {
        printf("%s not found", file);
        return 0;
    }

    fscanf(ptr,"%d %d %d", &X,&Y,&Z);

    for (i = 0; i < Y; ++i)
    {
        fscanf(ptr,"%d %d %d", &A[i],&B[i],&C[i]);
    }
    
    switch(X){
        case 0: FirstComeFirstServe(Y,A,B,C); break;
        case 1: ShortJobFirst(A,B,C); break;
        case 2: ShortRemainTimeFirst(A,B,C); break;
        case 3: RoundRobin(A,B,C); break;
    }
  //printf("Hello World\n");
  return 0;
}
