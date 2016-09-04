/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3
*/

#include<conio.h>
#include<stdio.h>
#include<iostream.h>
#include<stdlib.h>
#include<graphics.h>

class cpuschedule
{
	int n,Bu[20];
	float Twt,Awt,A[10],Wt[10],w;
public:
	void Getdata();
	void Fcfs();
	void Sjf();

};

void cpuschedule::Getdata()
{
	int i;
	cout<<"Enter the no of processes:\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter The BurstTime for Process p"<<i<<"=	";
		cin>>Bu[i];
	}
}


void cpuschedule::Fcfs()
{
	int i,B[10],B_temp[10];
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p"<<i<<"=	";
		cout<<B[i]<<endl;
		B_temp[i]=Bu[i];
	}
	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}

	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt<<endl;
	cout<<"Average Weighting Time="<<Awt<<" "<<endl;
	i=1;
       //	int l=5;
	while(i<=n)
	{
		while(B_temp[i]>0)
		{    //   int gd=DETECT,gm;
		    //	int s,a;
		   //	initgraph(&gd,&gm,"d:\\borlandc\\bgi");
		  //	rectangle(a+l,s,a+10+l,s+10);
			cout<<"p"<<i<<" | ";
		  //	closegraph();
			B_temp[i]=B_temp[i]-1;
		  //	l++;
		}
		i++;
	}
}

void cpuschedule::Sjf()
{
	int i,j,temp,B[10],B_temp[10],total_burst=0;
	Twt=0.0;
	for(i=1;i<=n;i++)
	{
		B[i]=Bu[i];
		cout<<"Burst time for process p"<<i<<"=	";
		cout<<B[i]<<endl;
		B_temp[i]=Bu[i];
		total_burst=total_burst+B_temp[i];
	}
	for(i=n;i>=1;i--)
	{
		for(j=1;j<=n;j++)
		{
			if(B[j-1]>B[j])
			{
				temp=B[j-1];
				B[j-1]=B[j];
				B[j]=temp;
			}
		}
	}

	Wt[1]=0;
	for(i=2;i<=n;i++)
	{
		Wt[i]=B[i-1]+Wt[i-1];
	}
	for(i=1;i<=n;i++)
		Twt=Twt+Wt[i];
	Awt=Twt/n;
	cout<<"Total   Weighting Time="<<Twt<<endl;
	cout<<"Average Weighting Time="<<Awt<<" "<<endl;
	i=1;
/*	int l=1;

	while(l<=total_burst)
	{

		i=0;
		while(i<=n)
		{       i++;
			if(B_temp[i]==0||B_temp[j]==0)
			continue;
			if(B_temp[i]<=B_temp[i+1])
			{
				if(B_temp[temp]<B_temp[i+1]);
				temp=i;
			}

		}




	cout<<"p"<<temp<<" | ";
	B_temp[i]-=1;
	l++;
	}
*/
}
void main()
{
	int ch,cho;
	cpuschedule c;
	do
	{       clrscr();
		cout<<"\n\n\n\n\n\n";
		cout<<"	  MENU\n";
		cout<<"1.Enter the BurstTime\n";
		cout<<"2.First Come First Served (nonpre-emtive)\n";
		cout<<"3.Shortest Job first (pre-emptive)\n";
		cout<<"4.EXIT\n";
		cout<<"Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1:
			c.Getdata();

			break;
		case 2:
			cout<<"FIRST COME FIRST SERVED SCHEDULING\n";
			c.Fcfs();
			getch();
			break;
		case 3:

			c.Sjf();
			getch();
			break;



		case 4:
			exit(0);
		}
	}while(ch<=4);
}


