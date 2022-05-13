#include "algo.h"
#include "struct.h"

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