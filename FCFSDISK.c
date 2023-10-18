#include<stdio.h>
int main()
{
	int in,s[10],i,j,t[100];
	printf("enter the intial head position");
	scanf("%d",&in);
	printf("enter the sequence ");
	for(i=0;i<8;i++)
	{
		scanf("%d",&s[i]);
		
	}
	for(i=0;i<7;i++)
	{
		for(j=i+1;j<8;j++)
		{
			t[i]=(s[i]-s[j]);
			if(t[i]<0)
			{
			t[i]*=-1;
			}
			printf("%d\n",t[i]);
			break;
		}
	}
	int tot=in-s[0];
	
 	for(i=0;i<7;i++)
	{
		tot+=t[i];
	}
	printf("\ntotal movement in fcfs %d",tot);
}

