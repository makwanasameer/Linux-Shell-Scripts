/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int hole[5]={0};
int h;
int process[4]={0};
int p;
int unallocate[4]={0};
int unalloc=0;
void get_hole(void);
void get_process(void);
void total_free_space(void);
void smallest_hole(void);
int found=0;
int n;
void sort(void);
int main()
{
	printf("Enter the choice\n");
	printf("1.first fit\n");
	printf("2.next  fit\n");
	printf("3.best fit\n");
	scanf("%d",&n);
	clrscr();
	switch(n)
	{
	case 1:

	get_hole();
	get_process();
	int i=0;

	while(i<p)
	{       int j=0;
		found=0;
		while(j<h)
		{
			if(process[i]<hole[j])
			{
				found=1;
			}
			if(found==1)
			{
				hole[j]-=process[i];
				break;
			}
			j++;
		}
		if(found==0)
		{
			unallocate[unalloc]=process[i];
			unalloc++;
		}
		i++;
	}

	total_free_space();
	smallest_hole();
	getch();
	break;

	case 2:
		get_hole();
		get_process();
		 i=0;
		int j=0;
		int count=j;
	while(i<p)
	{
		found=0;
		j=count+1;
		while(count<h&&j<h)
		{
			if(process[i]<hole[j])
			{
				found=1;
			}
			if(found==1)
			{
				hole[j]-=process[i];
				count=j;
				j++;
				break;
			}
			j++;
		}
		if(found==0)
		{
			unallocate[unalloc]=process[i];
			unalloc++;
		}
		i++;
	}

	total_free_space();
	smallest_hole();


		 getch();
		 break;

	case 3:
		get_hole();
		get_process();
		i=0;

	while(i<p)
	{       sort();
		int j=0;
		found=0;
		while(j<h)
		{
			if(process[i]<hole[j])
			{
				found=1;
			}
			if(found==1)
			{
				hole[j]-=process[i];
				break;
			}
			j++;
		}
		if(found==0)
		{
			unallocate[unalloc]=process[i];
			unalloc++;
		}
		i++;
	}

	total_free_space();
	smallest_hole();
	getch();
	break;
}






	return (0);
}




void get_hole(void)
{
	printf("Enter how many holes: you want to enter?");
	scanf("%d",&h);
	for(int i=0;i<h;i++)
	{
		scanf("%d",&hole[i]);
	}
}
void get_process(void)
{
	printf("Enter how many processes you want to enter?");
	scanf("%d",&p);
	for(int i=0;i<p;i++)
	{
		scanf("%d",&process[i]);
	}
}
void total_free_space(void)
{
	int i=0;
	int total_space=0;
	for(i=0;i<h;i++)
	{
		total_space+=hole[i];
	}
	printf("The total free space available is %d\n",total_space);
}
void smallest_hole(void)
{
	int temp[10]={0};
	int m=0;
	for(int i=0;i<h;i++)
	{
		if(hole[i]==0)
		{
			continue;
		}
		else
		{
			temp[m]=hole[i];
			m++;
		}
	}
	int j;
	int temporary;
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(temp[i]>temp[j])
			{
				temporary=temp[i];
				temp[i]=temp[j];
				temp[j]=temporary;
			}
		}
	}
	printf("The minimum hole size is %d\n",temp[0]);

	printf("The maximum hole size is %d\n",temp[m-1]);

}

void sort(void)
{
	int temp[10]={0};
	int m=0;
	for(int i=0;i<h;i++)
	{
			temp[m]=hole[i];
			m++;
	}
	int j;
	int temporary;
	for(i=0;i<m-1;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(temp[i]>temp[j])
			{
				temporary=temp[i];
				temp[i]=temp[j];
				temp[j]=temporary;
			}
		}
	}
	for(i=0;i<h;i++)
	{
		hole[i]=temp[i];
	}

}




