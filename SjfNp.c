#include<stdio.h>
#include<string.h>
int n,Bu[20],Twt,Ttt,A[10],Wt[10],w;
float Awt,Att;
char pname[20][20],c[20][20];
void Getdata();
void Gantt_chart();
void Calculate();
void SjfNp();
void Getdata()
{
    int i;
     printf("\n\n\t\tSHORTEST JOB FIRST NON-PREEMPTIVE ALGORITHM");
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fflush(stdin);
        printf("\n\nEnter the process name: ");
        scanf("%s",&pname[i]);
        printf("\nEnter the arrival Time for Process %s =  ",pname[i]);
        scanf("%d",&A[i]);
        printf("\nEnter the burst Time for Process %s = ",pname[i]);
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
//Shortest job First Algorithm with NonPreemption
void SjfNp()
{
    int w,t,i,j,Tt=0,temp,temp1;
    char S[10];
    Twt=0;
    Ttt=0;
    w=0;
    for(i=1;i<=n;i++)
    {
        S[i]='T';
        Tt=Tt+Bu[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=3;j<=n;j++)
        {
            if(Bu[j-1]>Bu[j])
            {
                temp=Bu[j-1];
                temp1=A[j-1];
                Bu[j-1]=Bu[j];
                A[j-1]=A[j];
                Bu[j]=temp;
                A[j]=temp1;
                strcpy(c[j-1],pname[j-1]);
                strcpy(pname[j-1],pname[j]);
                strcpy(pname[j],c[j-1]);
            }
        }
    }
    //For the 1st process
    Wt[1]=0;
    w=w+Bu[1];
    t=w;
    S[1]='F';
    while(w<Tt)
    {
        i=2;
        while(i<=n)
        {
            if(S[i]=='T'&&A[i]<=t)
            {
                Wt[i]=w;
                S[i]='F';
                w=w+Bu[i];
                t=w;
                i=2;
            }
            else
                i++;
        }
    }
    //CALCULATING AVERAGE WAITING TIME AND AVERAGE TURN AROUND TIME
    for(i=1;i<=n;i++)
    {
        Twt=Twt+(Wt[i]-A[i]);
        Ttt=Ttt+((Wt[i]+Bu[i])-A[i]);
    }
    Awt=(float)Twt/n;
    Att=(float)Ttt/n;
    printf(" Average Waiting Time = %3.2f",Awt);
    printf("\n Average Turn around time = %3.2f\n",Att);
    Gantt_chart();
}
void main()
{
    Getdata();
    SjfNp();
}
