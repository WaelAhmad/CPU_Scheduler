#include<stdio.h>
int main()
{
    int arrival[10],bu[10],rt[10],endTime,i,smallest,processGantt[100];
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;
    printf("\n\n\t\tPREEMPTIVE SHORTEST JOB FIRST ALGORITHM");
    printf("\nEnter no of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter arrival time for Process P%d : ",i+1);
        scanf("%d",&arrival[i]);
        printf("Enter burst time for Process P%d : ",i+1);
        scanf("%d",&bu[i]);
        rt[i]=bu[i];
    }
    printf("\n\nProcess\t|Waiting time\t|Turnaround time\n");
    rt[9]=9999;
    for(time=0;remain!=n;time++)
    {
        smallest=9;
        for(i=0;i<n;i++)
        {
            if(arrival[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                processGantt[time]=i;
                smallest=i;
            }
        }
        rt[smallest]--;
        if(rt[smallest]==0)
        {
            remain++;
            endTime=time+1;
            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-bu[smallest]-arrival[smallest],endTime-arrival[smallest]);
            sum_wait+=endTime-bu[smallest]-arrival[smallest];
            sum_turnaround+=endTime-arrival[smallest];
        }
    }
    printf("\n\nAverage Waiting time = %f\n\n",sum_wait*1.0/n);
    printf("Average Turnaround time = %f\n\n",sum_turnaround*1.0/n);
    for(i=0;i<=time-1;i++)
    {
        printf("%d->P%d ",i,processGantt[i]+1);
    }
    return 0;
}
