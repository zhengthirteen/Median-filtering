#include<stdio.h>
void order(int x[],int m)
{
	int temp;
	for(int i=0;i<m-1;i++)
	{
		for(int j=i+1;j<m;j++)
		{
			if(x[i]>x[j])
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
int readnumber(void)
{
	char ch,x[10];
	int a=0,n,sum=0;
	while((ch=getchar())!='\n'&&ch!=' ')
	{
		if(ch>='0'&&ch<='9')
		x[a++]=ch;
	}
	x[a]='\0';
	for(int i=0;i<a;i++)
	{
		sum=sum*10+x[i]-'0';
	}
	return sum;
}
int main(void)
{
	int n,m,y[10][100]={0},a=0;
	char ch;
	while((ch=getchar())!=EOF)
	{
		m=ch-'0';
		getchar();
		n=readnumber();
		int x[n];
		for(int i=0;i<n;i++)
		{
			x[i]=readnumber();
		}
		if(m%2!=0)
		{
			for(int i=0;i<m/2;i++)
			{
				y[a][i]=x[i];
			}
			for(int i=n-m/2;i<n;i++)
			{
				y[a][i]=x[i];
			}
			for(int i=m/2;i<n-m/2;i++)
			{
				int z[m],temp=i-m/2;
				for(int j=0;j<m;j++)
				{
					z[j]=x[temp++];
				}
				order(z,m);
				y[a][i]=z[m/2];
			}
		}
		else
		{
			y[a][0]=0;
		}
		a++;
	}
	for(int i=0;i<a;i++)
	{
		int j=0;
		if(y[i][0]==0)
		printf("ERROR\n");
		else
		{
			while(y[i][j]!=0)
		{
			printf("%d ",y[i][j++]);
		}
		printf("\n");
		}
	}
	return 0;
}
