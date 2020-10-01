#include<stdio.h>
 
int array[10][10],done[10],n;
int cost=0;
 
void input()
{
	int i,j;
 
	printf("Enter the number of villages: ");
	scanf("%d",&n);
 
	printf("\nEnter the Cost Matrix\n");
 
	for(i=0;i < n;i++)
	{
		printf("\nEnter Elements of Row: %d\n",i+1);
 
		for( j=0;j < n;j++)
			scanf("%d",&array[i][j]);
 
		done[i]=0;
	}
 
	printf("\n\nThe cost list is:");
 
	for( i=0;i < n;i++)
	{
		printf("\n");
 
		for(j=0;j < n;j++)
			printf("\t%d",array[i][j]);
	}
}
 
void mincost(int city)
{
	int i,ncity;
 
	done[city]=1;
 
	printf("%d--->",city+1);
	ncity=least(city);
 
	if(ncity==999)
	{
		ncity=0;
		printf("%d",ncity+1);
		cost+=array[city][ncity];
 
		return;
	}
 
	mincost(ncity);
}
 
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++)
	{
		if((array[c][i]!=0)&&(done[i]==0))
			if(array[c][i]+array[i][c] < min)
			{
				min=array[i][0]+array[c][i];
				kmin=array[c][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
 
int main()
{
	input();
 
	printf("\n\nThe Path is:\n");
	mincost(0); 
 
	printf("\n\nMinimum cost is %d\n ",cost);
 
	return 0;
}