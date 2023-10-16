#include<stdio.h>
int main()
{
    int b[20],p[20],wt[20],tat[20],i,j,n,tot_w=0,tot_t=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&b[i]);
        p[i]=i+1;
    }
 
    //sorting of burst times
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(b[j]<b[i])
              temp=b[i];
        		b[i]=b[pos];
        		b[pos]=temp;
        }
 
        
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
  	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=b[i-1]+wt[i-1];
		tot_w+=wt[i];
		
	}
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i]+b[i];
		tot_t+=tat[i];
	}
	printf("process		bursttime	waitingtime	turnaroundtime\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",p[i]);
		printf("%d\t\t",b[i]);
		printf("%d\t\t",wt[i]);
		printf("%d\t\t",tat[i]);
		printf("\n");
		}
	printf("\navg turn around time is %d",tot_t/n);
	printf("avg waiting time is %d",tot_w/n);
}
 
  
 