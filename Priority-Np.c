void drawGanttChart();
#include<stdlib.h>
#include<stdio.h>
int n,time,*arrival,*bu,*processNumber,smallest,*priority;
float sum_wait=0;

int main()
{
                int i,j,temp;
                printf("\n\n\t\tN0N-PREEMPTIVE PRIORITY ALGORITHM");
                printf("\nEnter no of processes : ");
                scanf("%d",&n);
                arrival=(int*)malloc(sizeof(int)*n);
                bu=(int*)malloc(sizeof(int)*n);
                processNumber=(int*)malloc(sizeof(int)*n);
                priority=(int *)malloc(sizeof(int)*n);
               
                smallest=2147483647;
                for(i=0;i<n;i++)
                {
                                processNumber[i]=i+1;
                                printf("Enter the arrival time for process p%d :",i+1);
                                scanf("%d",&arrival[i]);
                                printf("Enter the burst time for process p%d :",i+1);
                                scanf("%d",&bu[i]);
                                printf("Enter the priority for process p%d :",i+1);
                                scanf("%d",&priority[i]);    
                                time+=bu[i];
                                if(smallest>arrival[i])
                                                smallest=arrival[i];
                }
               
                /*
                                implementing bubble sort algorithm
                */
               
                for(i=0;i<n;i++)
                {
                                for(j=0;j<n-i-1;j++)
                                {
                                                if(priority[j]>priority[j+1])
                                                {
                                                                temp=priority[j];
                                                                priority[j]=priority[j+1];
                                                                priority[j+1]=temp;
                                               
                                                                temp=arrival[j];
                                                                arrival[j]=arrival[j+1];
                                                                arrival[j+1]=temp;
                                                               
                                                                temp=bu[j];
                                                                bu[j]=bu[j+1];
                                                                bu[j+1]=temp;
                                                                                               
                                                                temp=processNumber[j];
                                                                processNumber[j]=processNumber[j+1];
                                                                processNumber[j+1]=temp;
                                                }
                                }
                }

               
                drawGanttChart();
               
}
void drawGanttChart()
{
                const int maxWidth=100;
                int scalingFactor,i,counter,tempi,currentTime;
                printf("\n\t\t\t GANTT CHART\n");
               
                scalingFactor=maxWidth/time;
                for(i=0;i<scalingFactor*time+2+n;i++)
                {
                                printf("-");
                }
                printf("\n|");
                counter=0,tempi=0;
                for(i=0;i<scalingFactor*time;i++)
                {
                                if(i==bu[counter]*scalingFactor+tempi)
                                {
                                                counter++;
                                                tempi=i;
                                                printf("|");
                                }
                                else if(i==(bu[counter]*scalingFactor)/2+tempi)
                                {
                                                printf("P%d",processNumber[counter]);
                                }
                                else
                                {
                                                printf(" ");
                                }
                               
                }
                printf("|");
                printf("\n");
                for(i=0;i<scalingFactor*time+2+n;i++)
                {
                                printf("-");
                }
                printf("\n");

                /* printing the time labels of the gantt chart */
                counter=0;
                tempi=0;
                currentTime=smallest;
                printf("%d",currentTime);
                for(i=0;i<scalingFactor*time;i++)
                {
                                if(i==bu[counter]*scalingFactor+tempi)
                                {
                                               
                                                tempi=i;
                                                currentTime+=bu[counter];
                                                sum_wait+=currentTime;
                                                counter++;
                                                printf("%2d",currentTime);
                                }
                                else
                                {
                                                printf(" ");
                                }
                }
                currentTime+=bu[counter];
               
                printf("%2d\n\n",currentTime);
                sum_wait=sum_wait/n;
                printf("Average waiting time: %f\n",sum_wait);
}
