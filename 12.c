#include<stdio.h>
int main()
{
	int block[10];
	int pro[10],i,j,temp[10],allo[10];
	printf("enter the block");
	for(i=0;i<5;i++)
	{
		scanf("%d",&block[i]);
	}
	printf("enter the process");
		for(i=0;i<4;i++)
	{
		scanf("%d",&pro[i]);
		
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			if(block[j]>=pro[i])
			{	
				allo[i]=j;
				block[j]-=pro[i];
				printf("%d",j+1);
				temp[i]=1;
				break;
			}
			
		}
	}
		printf("\nprocess no.\tsize\t\block no.\t\t");
		for(i = 0; i < 4; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, pro[i]);
		if(allo[i]!=0)
			printf("%d\t\t\t",allo[i]+1);
			
		else
			printf("not allocated");
	}

}