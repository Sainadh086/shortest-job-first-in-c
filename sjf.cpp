#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat; 
    printf("\nEnter 5 positive Burst Time:\n");
    while(i<5)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1; 
		i++;        //contains process number   
    }
 
    //sorting burst time in ascending order using selection sort
    for(i=0;i<5;i++)
    {
        pos=bt[i];
        j=i-1;
        while(j>=0&&bt[j]>pos)
        {
        	bt[j+1]=bt[j];
        	j=j-1;
		}
		bt[j+1]=pos;
	}
		
       
 
    wt[0]=0;            //waiting time for first process will be zero      
 
    //calculate waiting time
    for(i=1;i<5;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/5;      //average waiting time   
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<5;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/5;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
