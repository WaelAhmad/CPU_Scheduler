#include<stdio.h>
int main()
{
  int i,j,n,time,sum_wait=0,sum_turnaround=0,smallest,processGantt[100];
  int arrival[10],bu[10],priority[10],rt[10],remain; //rt = remaining Time
  printf("\n\n\t\tPREEMPTIVE PRIORITY ALGORITHM");
  printf("\nEnter no of Processes : ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter the arrival time for process p%d :",i+1);
    scanf("%d",&arrival[i]);
    printf("Enter the burst time for process p%d :",i+1);
    scanf("%d",&bu[i]);
    printf("Enter the priority for process p%d :",i+1);
    scanf("%d",&priority[i]);
    rt[i]=bu[i];
  }
  priority[9]=11;
  printf("\n\nProcess\t|Waiting time\t|Turnaround time\n");
  for(time=0;remain!=0;time++)
  {
    smallest=9;
    for(i=0;i<n;i++)
    {
      if(arrival[i]<=time && priority[i]<priority[smallest] && rt[i]>0)
      {
         processGantt[time]=i;
         smallest=i;
      }
    }
    rt[smallest]--;
    if(rt[smallest]==0)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+1-arrival[smallest]-bu[smallest],time+1-arrival[smallest]);
      sum_turnaround+=time+1-arrival[smallest];
      sum_wait+=time+1-arrival[smallest]-bu[smallest];
    }
  }
  printf("\n\nAverage waiting time = %f\n\n",sum_wait*1.0/n);
  printf("Average turnaround time = %f\n\n",sum_turnaround*1.0/n);
  for(i=0;i<=time-1;i++)
  {
     printf("%d->P%d ",i,processGantt[i]+1);
  }
  return 0;
}
