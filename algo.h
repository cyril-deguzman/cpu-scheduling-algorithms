typedef struct process
{
  int id;
  int arrival;
  int burst;
  int start;
  int wait;
  int end;
} Process;

void FirstComeFirstServe(int, Process[]);

void ShortJobFirst(int, Process[]);

void ShortRemainTimeFirst(int, Process[]);

void RoundRobin(Process[]);

void SortBurst(Process[], int);

void Swap(Process*, Process*);