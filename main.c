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
    int i;
    
    Process p[100];
    Process *process_ptr = NULL;
    process_ptr = p;

    printf("Enter file name: ");
    scanf("%s", file);
    
    FILE* ptr = fopen(file, "r");
    if (ptr == NULL) {
        printf("%s not found", file);
        return 0;
    }

    fscanf(ptr,"%d %d %d", &X,&Y,&Z);

    for (i = 0; i < Y; i++)
    {
        fscanf(ptr,"%d %d %d", &process_ptr->id, &process_ptr->arrival, &process_ptr->burst);
        process_ptr++;
    }
    
    switch(X){
        case 0: FirstComeFirstServe(Y, p); break;
        case 1: ShortJobFirst(Y, p); break;
        case 2: ShortRemainTimeFirst(p); break;
        case 3: RoundRobin(p); break;
    }
  //printf("Hello World\n");
  return 0;
}
