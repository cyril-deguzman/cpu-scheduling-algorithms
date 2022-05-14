typedef struct process
{
  int id;
  int arrival;
  int burst;
  int start;
  int wait;
} Process;

void FirstComeFirstServe(int, Process[]);

void ShortJobFirst(int, Process[]);

void ShortRemainTimeFirst(Process[]);

void RoundRobin(Process[]);

void SortBurst(Process[], int);

void SortArrival(Process[], int);

void Swap(Process*, Process*);