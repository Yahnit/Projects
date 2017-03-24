#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>

long long int c[2001],d[2001],a[2001][2001]={0},max=1000000009; 
long long int temp[2001][2001],distance[2001],pred[2001],startnode=0;;
long long  int visited[2001],count,mindistance,nextnode,i,j;

long long shortest_dist(long long int n)
{
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]==0)
				temp[i][j]=max;
			else
				temp[i][j]=a[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=temp[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=0;

	while(count<n-1)
	{
		mindistance=max;
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(mindistance+temp[nextnode][i]<distance[i])
				{
					distance[i]=mindistance+temp[nextnode][i];
					pred[i]=nextnode;
				}
		count++;
	}
   /* for(i=0;i<n;i++)
       printf("%lld ",distance[i]+c[0]);*/
	return distance[n-1];
} 
int main()
{
	long long int n,i,j;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&c[i]);
	for(i=0;i<n-1;i++)
		scanf("%lld",&d[i]);

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<=i+d[i] && j<n;j++)
		{
			a[i][j]=c[j];
		} 
	}


	long long int ans= shortest_dist(n)+c[0];
	printf("%lld\n",ans);

/*		for(i=0;i<n;i++)
		{
		for(j=0;j<n;j++)
		printf("%lld ",a[i][j]);
		printf("\n");
		}*/
	return 0;
}

