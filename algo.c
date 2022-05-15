#include <stdio.h>
#include <stdlib.h>
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
    SortArrival(p,num);
    FirstComeFirstServe(num, p);
    
    for(i; i < num; i++) {
      printf("\n%d", p[i].end);
    }
}

void ShortRemainTimeFirst(int num, Process p[]){
    const int SENTINEL = 999;
    int i, j;
    int time = 0;
    int isDone = 0;
    int handler_idx = 0;
    int shortest_idx = 0;
    Process *handler = malloc(num * sizeof(*handler));

    while(!isDone) {
      // add to handler those who arrived at current time
      if(handler_idx < num) 
        for(i = 0; i < num; i++) 
          if(time == p[i].arrival) 
          {
            handler[handler_idx] = p[i];
            handler_idx++;
          }
      
      if(handler_idx) 
      {
        // get shortest remaining time in handler by comparing burst times
        for(i = 0; i < handler_idx; i++)
          if(handler[shortest_idx].burst > handler[i].burst && handler[i].burst != 0)
            shortest_idx = i;
        
        // decrease burst of shortest
        handler[shortest_idx].burst--;
        if(handler[shortest_idx].burst == 0)
          handler[shortest_idx].burst = SENTINEL;

        printf("time: %d pid: %d burst: %d \n", time, handler[shortest_idx].id, handler[shortest_idx].burst);
        
        // add wait time
        for(i = 0; i < handler_idx; i++)
          if(shortest_idx != i)
            handler[i].wait++;
      }

      // check if all processes are done executing
      if(handler_idx == num)
        for(i = 0, j = 0; i < num; i++)
          if(handler[i].burst == SENTINEL)
            j++;
      
      if(j == num)
        isDone = 1;

      time++;
    }
}

void RoundRobin(int num, int q, Process p[]){
    const int SENTINEL = 999;
    int i, hasExecuted = 0;
    int q_check = 0;
    int time = 0;
    int isDone = 0;
    int handler_idx = 0;
    int curr_idx = 0;
    Process *handler = malloc(num * sizeof(*handler));

    while(!isDone) {
      // add to handler those who arrived at current time
      if(handler_idx < num) 
        for(i = 0; i < num; i++) 
          if(time == p[i].arrival) 
          {
            handler[handler_idx] = p[i];
            handler_idx++;
          }
      
      if(handler_idx - hasExecuted) 
      { 
        // check burst of curr_idx
        while(handler[curr_idx].burst == SENTINEL) {
          printf("curr_idx: %d burst: %d\n", curr_idx, handler[curr_idx].burst);
          Traverse(&curr_idx, &handler_idx, &q_check);
        }
          
          
        // decrement burst
        if(q_check < q) {

          handler[curr_idx].burst--;
          printf("pid: %d burst: %d\n", handler[curr_idx].id, handler[curr_idx].burst);
          HandleZero(&handler[curr_idx], &hasExecuted);

        } else if(q_check == q) {
          Traverse(&curr_idx, &handler_idx, &q_check);

          while(handler[curr_idx].burst == SENTINEL) {
            printf("2: curr_idx: %d burst: %d\n", curr_idx, handler[curr_idx].burst);
            Traverse(&curr_idx, &handler_idx, &q_check);
          }

          handler[curr_idx].burst--;
          printf("pid: %d burst: %d\n", handler[curr_idx].id, handler[curr_idx].burst);
          HandleZero(&handler[curr_idx], &hasExecuted);
        } 
        
        // inc q_check
        q_check++;

        // add wait time
        for(i = 0; i < handler_idx; i++)
          if(curr_idx != i && handler[i].burst != SENTINEL)
            handler[i].wait++;
      }
      
      if(hasExecuted == num)
        isDone = 1;

      time++;
    }
}

void SortBurst(Process p[], int num){
    int i, j;

    for(i = 0; i < num; i++)
      for(j = i+1; j < num; j++) 
        if(p[i].burst > p[j].burst)
          Swap(&p[i], &p[j]); 
}

void SortArrival(Process p[], int num){
    int i, j;

    for(i = 0; i < num; i++)
      for(j = i+1; j < num; j++) 
        if(p[i].arrival > p[j].arrival)
          Swap(&p[i], &p[j]); 
}

void Swap(Process *x, Process *y) {
    Process temp = *x;
    *x = *y;
    *y = temp;
}

void Traverse(int* curr_idx, int* handler_idx, int* q_check) {
  *curr_idx+= 1;

  if(*curr_idx >= *handler_idx)
    *curr_idx = 0;
  
  *q_check = 0;
}

void HandleZero(Process *p, int* hasExecuted) {
  const int SENTINEL = 999;
  
  if((*p).burst == 0) {
    (*p).burst = SENTINEL;
    *hasExecuted+= 1;
  }
}