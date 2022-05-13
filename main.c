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

void FirstComeFirstServe(int num, int A[], int B[], int C[]){
    int count = 0, total = 0, i, start = 0, wait = 0, end = 0;
    float ave = 0;

    printf("\n:::::::FIRST COME FIRST SERVE:::::::\n\n");
    
    for(i = 0; i < num; ++i){
        
        printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", A[i], start, C[i] + end, wait);
        
        end = C[i] + wait;
        start = end;
        ave = ave + wait;
        wait = end;
    }
    ave = ave / num;
    printf("Average Wait Time: %.1f", ave);

}

void ShortJobFirst(int A[], int B[], int C[]){
    printf("\n:::::::SHORTEST JOB FIRST:::::::\n\n");
    
}

void ShortRemainTimeFirst(int A[], int B[], int C[]){
    printf("\n:::::::SHORTEST REMAINING TIME FIRST:::::::\n\n");
}

void RoundRobin(int A[], int B[], int C[]){
    printf("\n:::::::ROUND ROBIN:::::::\n\n");
}


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
