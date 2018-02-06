#include<stdio.h>
int main()
{
  int i,j=0,n,time,remain,flag=0,ts;
  int sum_wait=0,sum_turnaround=0,arrival[10],bu[10],rt[10];
  int ganttP[50],ganttStartTime[50];
  printf("\n\n\t\tROUNDROBIN ALGORITHM");
  printf("\nEnter no of Processes : ");
  scanf("%d",&n);
  remain=n;
  for(i=0;i<n;i++)
  {
    printf("Enter the arrival time for Process P%d : ",i+1);
    scanf("%d",&arrival[i]);
    printf("Enter the burst time for Process P%d : ",i+1);
    scanf("%d",&bu[i]);
    rt[i]=bu[i];
  }
  printf("Enter quantum = ");
  scanf("%d",&ts);
  printf("\n\nProcess\t|Waiting time\t|Turnaround time\n");
  for(time=0,i=0;remain!=0;)
  {
    if(rt[i]<=ts && rt[i]>0)
    {
      ganttP[j]=i+1;
      ganttStartTime[j++]=time;
      time+=rt[i];
      rt[i]=0;
      flag=1;
    }
    else if(rt[i]>0)
    {
      ganttP[j]=i+1;
      ganttStartTime[j++]=time;
      rt[i]-=ts;
      time+=ts;
    }
    if(rt[i]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrival[i]-bu[i],time-arrival[i]);
      sum_wait+=time-arrival[i]-bu[i];
      sum_turnaround+=time-arrival[i];
      flag=0;
    }
    if(i==n-1)
      i=0;
    else if(arrival[i+1]<=time)
      i++;
  }
  printf("\nAverage waiting time = %f\n",sum_wait*1.0/n);
  printf("Average turnaround time = %f",sum_turnaround*1.0/n);
  printf("\n\n");
  for(i=0;i<j;i++)
  {
      printf("(P[%d],%d) ",ganttP[i],ganttStartTime[i]);
  }
  return 0;
}
