#include <stdio.h>
#include "algo.h"

void FirstComeFirstServe(int num, Process p[]){
    int count = 0, total = 0, i, start = 0, wait = 0, end = 0;
    float ave = 0;
    
    for(i = 0; i < num; i++){
        
        printf("P[%d] Start Time: %d End time: %d | Waiting time: %d\n", p[i].id, start, p[i].burst + end, wait);
        
        end = p[i].burst + wait;
        start = end;
        ave = ave + wait;
        wait = end;
    }
    ave = ave / num;
    printf("Average Wait Time: %.1f", ave);

}

void ShortJobFirst(int num, Process p[]){
    int i = 0;

    SortBurst(p, num);
    FirstComeFirstServe(num, p);
    
    for(i; i < num; i++) {
      printf("%d %d %d", p[i].id, p[i].arrival, p[i].burst);
    }
}

void ShortRemainTimeFirst(Process p[]){
     
}

void RoundRobin(Process p[]){
    
}

void SortBurst(Process p[], int num){
    int i, j;

    for(i = 0; i < num; i++)
      for(j = i+1; j < num; j++) 
        if(p[i].burst > p[j].burst)
          Swap(&p[i], &p[j]); 
}

void Swap(Process *x, Process *y) {
    Process temp = *x;
    *x = *y;
    *y = temp;
}