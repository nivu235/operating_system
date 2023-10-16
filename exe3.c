#include<stdio.h>
int main()
{
	int np,tot_t,tot_w=0,i;
	int pr[10];
	int b[10],wt[10],tat[10];
	printf("enter the no of process");
	scanf("%d",&np);
	printf("enter the process id");
	for(i=0;i<np;i++)
	{
		scanf("%d",&pr[i]);
	}
	printf("enter the burst time");
	for(i=0;i<np;i++)
	{
		scanf("%d",&b[i]);
	}
	wt[0]=0;
	for(i=1;i<np;i++)
	{
		wt[i]=b[i-1]+wt[i-1];
		tot_w+=wt[i];
		
	}
	for(i=0;i<np;i++)
	{
		tat[i]=wt[i]+b[i];
		tot_t+=tat[i];
	}
	printf("process		bursttime	waitingtime	turnaroundtime\n");
	for(i=0;i<np;i++)
	{
		printf("%d\t\t",pr[i]);
		printf("%d\t\t",b[i]);
		printf("%d\t\t",wt[i]);
		printf("%d\t\t",tat[i]);
		printf("\n");
		}
	printf("\navg turn around time is %d",tot_t/np);
	printf("avg waiting time is %d",tot_w/np);
	
}