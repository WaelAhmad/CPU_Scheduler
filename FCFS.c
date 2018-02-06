#include<stdio.h>
#include<string.h>
int n,Bu[20],Twt,Ttt,arrival[10],Wt[10],w;
float Awt,Att;
char pname[20][20],c[20][20];
void Getdata();
void Gantt_chart();
void Calculate();
void fcfs();

void Getdata()
{
	int i;
        printf("\n\n\t\tFIRST COME FIRST SERVED ALGORITHM");
	printf("\nEnter the number of processes: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the process name: ");
		scanf("%s",&pname[i]);
		printf("Enter the arrival Time for Process %s =  ",pname[i]);
		scanf("%d",&arrival[i]);
		printf("Enter The burst Time for Process %s =  ",pname[i]);
		scanf("%d",&Bu[i]);
	}
}
void Gantt_chart()
{
	int i;
	printf("\n\t\t\t GANTT CHART\n");
	printf("\n\t|--------------------------------------------|\n");
	printf("\t|");
	for(i=1;i<=n;i++)
		printf("   %s   |",pname[i]);
		printf("\n\t|--------------------------------------------|\n");
	printf("        ");
	for(i=1;i<=n;i++)
	printf("%d        ",Wt[i],"\n");
	printf("%d",Wt[n]+Bu[n],"\n\t\n\n");
 }
void Calculate()
{
	int i;
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=Bu[i-1]+Wt[i-1];
	}
	for(i=1;i<=n;i++)
	{
		Twt=Twt+(Wt[i]-arrival[i]);
		Ttt=Ttt+((Wt[i]+Bu[i])-arrival[i]);
	}
	Awt=(float)Twt/n;
	Att=(float)Ttt/n;
	printf(" \n\nAverage waiting time = %3.2f\n",Awt);
	printf("\nAverage turnaround time = %3.2f\n",Att);
}
void fcfs()
{
	int i,j,temp, temp1;
	Twt=0;
	Ttt=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(arrival[i]>arrival[j])
			{
				temp=Bu[i];
				temp1=arrival[i];
				Bu[i]=Bu[j];
				arrival[i]=arrival[j];
				Bu[j]=temp;
				arrival[j]=temp1;
				strcpy(c[i],pname[i]);
				strcpy(pname[i],pname[j]);
				strcpy(pname[j],c[i]);
			}
		}
	}
	Calculate();
	Gantt_chart();
}
void main()
{
	Getdata();
	fcfs();
}
